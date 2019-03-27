# ANTRASND

### :rocket:[V0.1](https://github.com/odiraitis/ANTRASND/releases/tag/v0.1)  release su masyvais.

### :rocket:[V0.1](https://github.com/odiraitis/ANTRASND/releases/tag/v0.1.2)  release su vektoriais.
-------------------------------------------------------------------------------

Jei norite įvesti naują mokinį spauskite bet kokį simboli tik ne **'f'**, paspaudus **f** baigiamas mokinių įvedinėjimas.

Jei norite, kad pažymiai būtų sugeneruoti spauskite **1**, jei norite juos ivesti rankiniu budu, spauskite **2**.

Jei galutinis pazymys skaiciuojamas su vidurkiu spauskite **1**, jei su mediana **2**.

Jei pasirinkote, jog skaicius turi buti sugeneruotas iveskite kiek skaiciu norite sugeneruoti.

Jei pasirinkote, jog norite ivesti pats skaicius, veskite po viena skaiciu ir spauskite Enter norint baigti spauskite bet koki simboli, taciau jis turi buti didesnis uz 1,mazesnis uz 10

Toliau reiks ivesti egzamino pazymi, bei mokinio varda, pavarde.

### :rocket:[V0.2](https://github.com/odiraitis/ANTRASND/releases/tag/v0.2.3) release su skaitymu iš failo.
-------------------------------------------------------------------------------

Realizacija skaitant is failo "kursiokai.txt".

Jei norite skaityti is duomenu failo spauskite **1**, jei ne tai spauskite **2**.

### :rocket:[V0.3](https://github.com/odiraitis/ANTRASND/releases/tag/v0.3) release su išskaidyta programa į funkc.cpp header.h main.cpp .
-------------------------------------------------------------------------------

Sukurti header ir funkcijų failai, taip pat makefile, norint subuildint reikia terminale rašyti make, norit išvalyti make clean.

### :rocket:[V0.4](https://github.com/odiraitis/ANTRASND/releases/tag/v0.4.1) release su failų generavimu.
-------------------------------------------------------------------------------

Sutvarkyta, jog nebutu naudojamos bereikalingos iš karto priskirto dydžio struktūros, pries išvedant kiečiukų ir nuskriaustukų failus, duomenis išsisaugau į vektoriu, tik tada išvedu į du failus.

### :rocket:[V0.5](https://github.com/odiraitis/ANTRASND/releases/tag/v0.5) release su atskirais konteineriais.
-------------------------------------------------------------------------------

V0.5.zip faile yra užduotys su:  
- std::deque.  
- std::list.   
- std::vector.   

Atskirus konteinerius naudoju tik kiečiukų ir nuskriaustukų kaupimui bei jų išvedimui.
Kadangi skaidau į du atskirus kiečiukų ir lievų konteinerius, tai su **std::vector** veikia greičiausiai, su **std::list** veikia lėčiausiai. Taigi labiausiai apsimoka naudoti vektorius, list nepatariu, nes jų sintaksė gana sudėtinga, o ir pats būdas ne toks efektyvus. **Todėl mano repozitorijoj bus failai tik su vektorium, su listu ir deque bus galima rasti V0.5 release esančiame zip faile.**

-------------------------------------------------------------------------------
### :rocket:[V1.0](https://github.com/odiraitis/ANTRASND/releases/tag/V1.0) release 2 strategija be algoritmų.
-------------------------------------------------------------------------------

**1 strategija** Būdas įgyvendintas ankstesniuose release, geriausiai veikia su std::vector

| std::vector | std::deque | std::list |
|:---:|:---:|:---:|
| 0.85s | 0.86s | 0.89s |

**2 strategija** Būdas įgyvendintas V1.0 release, geriausiai veikia su std::list, nes su std::vector ir std::deque reikia perstumdyti elementus.

| std::vector | std::deque | std::list |
|:---:|:---:|:---:|
| 78.0s | 75.0s | 0.85s |
### :rocket:[V1.0](https://github.com/odiraitis/ANTRASND/releases/tag/V1.3) release 2 strategija su algoritmais.
-------------------------------------------------------------------------------
 **2 strategija su algoritmais** Pridėti algoritmai, taigi greičiausiai veikia vektorius.
 
**PAPILDYTA**

| std::vector | std::deque | std::list |
|:---:|:---:|:---:|
| 0.08s | 0.09s | 0.08s |

Naudojau `remove_if` ir `remove_copy_if`
```c++
remove_copy_if(A.begin(), A.end(),
                       back_inserter(lievi), negavoSkolos);
        A.erase(remove_if(A.begin(), A.end(),
                        gavoSkolos), A.end());
```

--------------------------------------------------------------------------------
### :rocket:[PAPILDOMA](https://github.com/odiraitis/ANTRASND/releases/tag/V1.2).

Su std::vector insertint i vektoriaus pradzia nera efektyvu, taciau su std::deque galima push frontint, taip uzduotis atliekama daug greiciau.

| std::vector | std::deque |
|:---:|:---:|
| 310s | 1.09s |

### :rocket:[PAPILDOMA](https://github.com/odiraitis/ANTRASND/releases/tag/V1.2) PAPILDOMOS PAPILDYMAS
optimizavau programa (maina isskaidziau i funkcijas). Dabar programa veikia daug greiciau.

| std::vector | std::deque |
|:---:|:---:|
| 5.3s | 0.08s |

Taip yra todel nes insert funkcija kiekviena karta tikrina 3 variantus(iterpti i norima vieta, iterpti i prieki, iterpti i gala), o push front tiesiog neturi nieko tikrint ir kelia i prieki.
**[V1.0](https://github.com/odiraitis/ANTRASND/releases/tag/V1.1) ATSISIŲSTI folderį, norint paleisti nueiti į folderį Terminalu ir parašyti make, tuomet ./main , kad paleistų ir viską baigus, jog neliktų seni failai, make clean (išvalyti visus .txt ir .o failus)**
