---
jupytext:
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.15.1
kernelspec:
  display_name: C++17
  language: C++17
  name: xcpp17
---

# TP : nombres premiers et dates ♣

Implantez les deux derniers exercices du <a href="TD.pdf">TD</a>.

```{code-cell}
#include <iostream>
using namespace std;
```

```{code-cell}
bool ex6_1(int n) {
    int S = sqrt(n);
    return S*S == n;
}
```

```{code-cell}
ex6_1(27)
```

```{code-cell}
void ex6_2(int n) {
    for (int i=2; i<=n; i++) { if (ex6_1(i)) { cout<<i<<endl; } }
}
```

```{code-cell}
ex6_2(37)
```

```{code-cell}
void ex6_3(int n) {
    int i = 0;
    int k = 2;
    while (i<n) {
        if (ex6_1(k)) { cout<<k<<endl; i++; }
        k++;
    }
}
```

```{code-cell}
ex6_3(12)
```

```{code-cell}
bool date_valide(int J, int M, int Y) {
    if (J*M <= 0) { return false; }
    if (M==1 || M==3 || M==5|| M==7 || M==8 || M==10 || M==12) { return J<=31; }
    else if (M==2) { return J<=28; }
    else { return J<=30; }
}
```

```{code-cell}
date_valide(29, 2, 1936)
```

```{code-cell}
void jour_suivant(int J, int M, int Y) {
    if (!date_valide(J, M, Y)) { cout<<"Date invalide"; return; }
    J++;
    if ((M==1 || M==3 || M==5|| M==7 || M==8 || M==10 || M==12) && J==32) { J=1; M++; }
    else if ((M==2) && J==29) { J=1; M++; }
    else if (!(M==1 || M==3 || M==5|| M==7 || M==8 || M==10 || M==12) && J==31) { J=1; M++; }

    if (M==13) { M=1; Y++; }
    cout << "Le jour suivant est le " << J << "/" << M << "/" << Y;
}
```

```{code-cell}
jour_suivant(30,4,1992)
```

```{code-cell}
bool date_valide(int J, int M, int Y) {
    if (J*M <= 0) { return false; }
    if (M==1 || M==3 || M==5|| M==7 || M==8 || M==10 || M==12) { return J<=31; }
    else if (M==2) {
        bool Bis = !(Y%400) || (!(Y%4) && (Y%100));
        return J<=28+Bis; }
    else { return J<=30; }
}
```

```{code-cell}
date_valide(29, 2, 2023)
```

```{code-cell}

```
