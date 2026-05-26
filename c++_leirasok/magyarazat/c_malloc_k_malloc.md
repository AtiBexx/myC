A Linux kernel `kmalloc()` függvénye lényegében a kernel saját memóriafoglalója — olyan, mint user space-ben a `malloc()`, csak kernel módban működik.

C-ben tipikusan:

```c
void* p = malloc(128);
```

Linux kernelben:

```c
void* p = kmalloc(128, GFP_KERNEL);
```

A különbség:

- `malloc()` → normál programoknak
- `kmalloc()` → kernel/driverek számára

Példa kernel driver jelleggel:

```c
struct Hallgato* h;

h = kmalloc(sizeof(struct Hallgato), GFP_KERNEL);

if (h == NULL)
{
    return -ENOMEM;
}

h->tanulmanyAtlag = 3.5;

kfree(h);
```

Itt:

- `kmalloc()` foglal memóriát
- `kfree()` szabadítja fel

mint:

- `malloc/free`

csak kernel verzióban.

A második paraméter (`GFP_KERNEL`) nagyon fontos.

Ez megmondja:

- milyen környezetben foglalunk
- alhat-e a kernel
- megszakításból jön-e
- mennyire sürgős
- stb.

Példák:

```c
GFP_KERNEL
```

normál kernel foglalás

```c
GFP_ATOMIC
```

interrupt/context esetén, ahol nem szabad várakozni

A kernelben azért speciális ez:

- nincs normál userspace heap
- nincs STL
- nincs `new/delete`
- nincs exception
- sokkal szigorúbb memória kontroll kell

És ezért kernel/driverek világában még ma is nagyon sok:

- raw pointer
- manuális memória
- kézi életciklus kezelés

van 