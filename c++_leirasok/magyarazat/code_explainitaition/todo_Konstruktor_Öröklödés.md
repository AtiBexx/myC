```cpp
class Hallgato
{
    public:
      Hallgato(std::string nev);
    
};
class VegzosHallgato : public Hallgato
{
    using Hallgato::Hallgato //az alap konstruktor öröklődése
}
```

**EZ UGYANOLYAN MINT EZ**

```cpp
class VegzosHallgato : public Hallgato
{
    public:
      VegzosHallgato(std::string nev);
      Hallgato(nev){}
};
```

