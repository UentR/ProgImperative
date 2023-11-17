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

# TP : Implanter les fonctions sinus et cosinus ♣

+++

Il est possible de calculer les fonctions sinus et cosinus de manière
analogue à l'exponentielle, avec les formules suivantes ($x$ est un
angle en radians) :

$$\begin{aligned}
    \cos(x) &= 1 - \frac{x^2}{2!} + \frac{x^4}{4!} - \frac{x^6}{6!} + \dots = \sum_{n=0}^{\infty} (-1)^{n}\frac{x^{2n}}{(2n)!}\\
    \sin(x) &= x - \frac{x^3}{3!} + \frac{x^5}{5!} - \frac{x^7}{7!} + \dots = \sum_{n=0}^{\infty} (-1)^{n}\frac{x^{2n+1}}{(2n+1)!}
  \end{aligned}$$

-   Copiez-collez ici vos fonctions `abs`, `egal`, `factorielle` et `puissance`

```{code-cell}
double Abs(double x) {
    if (x<0) { return -x; }
    return x;
}
```

```{code-cell}
bool egal(double x, double y, double E) {
    double Ax = Abs(x);
    double Ay = Abs(y);
    double Axy = Abs(x-y);
    return (Axy<=E*Ax) && (Axy<=E*Ay);
}
```

```{code-cell}
double puissance(double x, int n) {
    if (n==0) { return 1; }
    else if (n==1) { return x; }
    return x * puissance(x, n-1);
}
```

```{code-cell}
double factorielle(int n) {
    if (n<=1) { return 1; }
    return n * factorielle(n-1);
}
```

-   Implantez des fonctions `sinPrecision` et `cosPrecision` sur le
    modèle de votre fonction `expPrecision` :

```{code-cell}
double sinPrecision(double x, double epsilon) {
    x = (x*0.01745329251);
    double lastSomme = 0;
    double currentSomme = 0;
    int N = 0;
    do {
        lastSomme = currentSomme;
        currentSomme += (puissance(x, 2*N+1) / factorielle(2*N+1)) * puissance(-1, N%2);
        N++;
    } while (!egal(lastSomme, currentSomme, epsilon));
    return currentSomme;
}
```

```{code-cell}
double cosPrecision(double x, double epsilon) {
    x = x*0.01745329251;
    double lastSomme = 1;
    double currentSomme = 1;
    int N = 1;
    do {
        lastSomme = currentSomme;
        currentSomme += (puissance(x, 2*N) / factorielle(2*N)) * puissance(-1, N%2);
        N++;
    } while (!egal(lastSomme, currentSomme, epsilon));
    return currentSomme;
}
```

-   Testez vos deux fonctions et comparez avec les fonctions `sin` et
    `cos` de `cmath` :

```{code-cell}
CHECK(Abs(sin(45*0.01745329251) - sinPrecision(45, 0.001)) <= 0.01);
CHECK(Abs(sin(0*0.01745329251) - sinPrecision(0, 0.001)) <= 0.01);
CHECK(Abs(sin(180*0.01745329251) - sinPrecision(180, 0.001)) <= 0.01);
CHECK(Abs(sin(-50*0.01745329251) - sinPrecision(-50, 0.001)) <= 0.01);

CHECK(Abs(cos(45*0.01745329251) - cosPrecision(45, 0.001)) <= 0.01);
CHECK(Abs(cos(0*0.01745329251) - cosPrecision(0, 0.001)) <= 0.01);
CHECK(Abs(cos(180*0.01745329251) - cosPrecision(180, 0.001)) <= 0.01);
CHECK(Abs(cos(-50*0.01745329251) - cosPrecision(-50, 0.001)) <= 0.01);
```

```{code-cell}
%timeit sin(10);
```

```{code-cell}
%timeit sinPrecision(10, 0.00000001);
```

```{code-cell}
%timeit cos(10);
```

```{code-cell}
%timeit cosPrecision(10, 0.00000001);
```

-   Implantez des fonctions `sinRapide` et `cosRapide` qui n'utilisent
    pas les fonctions `puissance` et `factorielle` :

```{code-cell}
double sinRapide(double x, double epsilon) {
    x = (x*0.01745329251);
    double currentSomme, lastSomme, puissance, fact;
    currentSomme = 0;
    puissance = x;
    double X = x*x;
    fact = 1;
    int n = 1;
    int i = 1;
    do {
        lastSomme = currentSomme;
        currentSomme += (puissance / fact) * i;
        fact *= 2*n * (2*n+1);
        n++;
        puissance *= X;
        i *= -1;
    } while (!egal(lastSomme, currentSomme, epsilon));
    return currentSomme;
}
```

```{code-cell}
double cosRapide(double x, double epsilon) {
    x = (x*0.01745329251);
    double currentSomme, lastSomme, puissance, fact;
    currentSomme = 1;
    double X = x*x;
    puissance = X;
    fact = 2;
    int n = 1;
    int i = -1;
    do {
        lastSomme = currentSomme;
        currentSomme += (puissance / fact) * i;
        fact *= 2*(n+1) * (2*n+1);
        n++;
        puissance *= X;
        i *= -1;
    } while (!egal(lastSomme, currentSomme, epsilon));
    return currentSomme;
}
```

```{code-cell}
CHECK(Abs(sin(45*0.01745329251) - sinRapide(45, 0.001)) <= 0.01);
CHECK(Abs(sin(0*0.01745329251) - sinRapide(0, 0.001)) <= 0.01);
CHECK(Abs(sin(180*0.01745329251) - sinRapide(180, 0.001)) <= 0.01);
CHECK(Abs(sin(-50*0.01745329251) - sinRapide(-50, 0.001)) <= 0.01);

CHECK(Abs(cos(45*0.01745329251) - cosRapide(45, 0.001)) <= 0.01);
CHECK(Abs(cos(0*0.01745329251) - cosRapide(0, 0.001)) <= 0.01);
CHECK(Abs(cos(180*0.01745329251) - cosRapide(180, 0.001)) <= 0.01);
CHECK(Abs(cos(-50*0.01745329251) - cosRapide(-50, 0.001)) <= 0.01);
```

```{code-cell}
%timeit sin(10);
```

```{code-cell}
%timeit sinRapide(10, 0.00000001);
```

```{code-cell}
%timeit cos(10);
```

```{code-cell}
%timeit cosRapide(10, 0.00000001);
```

```{code-cell}

```
