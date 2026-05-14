# Git parancsok – gyors útmutató

## Egyszer kell – beállítás
```bash
git config --global user.name "Neved"
git config --global user.email "email@gmail.com"
```

## Új repo létrehozása és feltöltése
```bash
git init
git add .
git commit -m "első commit"
git remote add origin URL
git push -u origin main
```

## Minden alkalommal – módosítás után
```bash
git add .
git commit -m "mit csináltál"
git push
```

## Mit csinál a git add . ?
- Minden **új fájlt** hozzáad
- Minden **módosított fájlt felülír** ha a tartalma változott
- Törölt fájlokat is jelez
- A régi commitok **mindig megmaradnak** a historiban – soha nem törlődnek!

## Tipp – értelmes commit üzenetek
```
"Login screen kész"
"Bug javítva a főmenüben"
"Főmenü gombok működnek"
```
Ne így: "asdfgh" vagy "javítás" 😄
