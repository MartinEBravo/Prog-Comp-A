# Teoría de Números

## Propiedades importantes:

$$0 \leq a - (a//b)b \leq b$$


$$(a+b) \% c = ((a\%c)+(b\%c))\%c$$
$$(a\cdot b)\% c= ((a\%c)\cdot(b\%c))\%c$$
$$(a\cdot b)\% c = ((((a\%c)-(b\%c))\%c)+c)\%c$$

## Máximo Común Divisor

$$ gcd(a,b)\begin{cases}
gcd(b,a) & a>b \\
b & a=0 \\
1 & b=0 \\
gcd(b\%a,a) & else
\end{cases}
$$

## Números primos

Algoritmo simple: $O(n)$

```c++
bool esPrimo(int x){
    for (int i = 0; i*i<x; i++){
        if (x % i == 0){
            return false;
        }
    }
    return true;
}
```

### Criba de Eratóstenes

Algoritmo de la criba: $O(n\log n)$

```c++
void sieveOfEratosthenes(int limit) {
    vector<bool> isPrime(limit + 1, true);

    for (int p = 2; p * p <= limit; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }
}
```
