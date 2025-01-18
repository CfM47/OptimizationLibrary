# Mínimos Cuadrados.

## Descripción del problema

El problema de mínimos cuadrados consiste en encontrar la función que más ajusta a un conjunto de puntos obtenidos mediante mediciones, utilizando el criterio como criterio de error el de mínimos cuadrados. Formalmente se tiene un conjunto de $n$ puntos $\{(x_k, y_k)\}_{k=1}^{n}$ y una base de funciones de $m$ funciones linealmente independientes de un espacio de funciones $\{f_j(x)\}_{j=1}^{n}$, y se quiere hallar $f(x)$, combinación lineal de las funciones base, o sea:

$$
f(x) = \sum_{j=1}^{m} c_jf_j(x)
$$

de forma tal que $f(x_k) \approx y_k $.

La aproximación por mínimos cuadrados se basa en la minimización del error cuadrático medio, definido como:

$$
E_{cm}(c) = \sqrt{\frac{\sum_{k=1}^{n}(y_k - f(x_k))^2}{n}}
$$

lo cual es equivalente a minimizar:

$$
S(c) = \sum_{k=1}^{n}(y_k - f(x_k))^2
$$

donde $c \in \real^n$ es el vector de parámetros $c_j$

## Solución al problema

La minimización de $S$ tiene solución cuando se trata de un problema de aproximación lineal sin importar las funciones base ($f(x_k)$ es una combinación lineal de la base).

**Proposición**: $S$ es una función convexa.

**Demostración**: La función de error cuadrático es:

$$
S(c) = \sum_{k=1}^{n} \left(y_k - f(x_k) \right)^2
$$

Derivemos $S(c)$ con respecto a un parámetro $c_i$:

$$
\frac{\partial S(c)}{\partial c_i} = \frac{\partial}{\partial c_j} \sum_{k=1}^{n}\left(y_k - f(x_k) \right)^2 = \sum_{k=1}^{n} \frac{\partial}{\partial c_i} \left(y_k - f(x_k) \right)^2
$$

dónde:

$$
\frac{\partial}{\partial c_i} \left(y_k - f(x_k) \right)^2 = 2 \left(y_k - f(x_k) \right)\frac{\partial f(x_k)}{\partial c_i} = -2 \left(y_k - \sum_{j=1}^{m} c_jf_j(x) \right)\frac{\partial}{\partial c_i} \sum_{j=1}^{m} c_jf_j(x)
$$

$$
\frac{\partial}{\partial c_i} \left(y_k - f(x_k) \right)^2 = -2 \left(y_k - \sum_{j=1}^{m} c_jf_j(x) \right)f_i(x)
$$

y sustituyendo se tiene:

$$
\frac{\partial S(c)}{\partial c_i} = -2 \sum_{k=1}^{n} f_i(x) \left(y_k - \sum_{j=1}^{m} c_jf_j(x) \right)
$$

Ahora derivamos nuevamente respecto a otro parámetro $c_l$ para obtener la segunda derivada parcial:

$$
\frac{\partial^2 S(c)}{\partial c_i \partial c_l} =
\frac{\partial}{\partial c_l}
\left(
-2 \sum_{k=1}^{n} f_i(x_k)
\left(
y_k - \sum_{j=1}^{m} c_j f_j(x_k)
\right)
\right).
$$

Se observa que:

$$
\frac{\partial}{\partial c_l}
\left(
y_k - \sum_{j=1}^{m} c_j f_j(x_k)
\right) =
-f_l(x_k).
$$

Sustituyendo, tenemos:

$$
\frac{\partial^2 S(c)}{\partial c_i \partial c_l} =
-2 \sum_{k=1}^{n} f_i(x_k)
\left(
-f_l(x_k)
\right)
=
2 \sum_{k=1}^{n} f_i(x_k) f_l(x_k).
$$

Tenemos que la matriz hessiana $H$ tiene como entradas $H_{ij}=2 \sum_{k=1}^{n} f_i(x_k) f_j(x_k)$. Notemos que una matriz $A$ con entradas $A_{ij}=f_i(x_k) f_j(x_k)$ la podemos expresar como $A=\Phi(x_k)\Phi(x_k)^T$ donde $\Phi(x_k)$ es el vector de las $m$ funciones $f_i(x_k)$. Con lo cual la Hessiana de $S(c)$ quedaría como:

$$
H = 2\sum_{k=1}^{n}\Phi(x_k)\Phi(x_k)^T
$$

Queremos demostrar que $H$ es semidefinida positiva. Es decir que para cualquier vector $z \in \R^m$ se cumple que $z^THz \geq 0$.
Sustituyendo H:

$$
z^THz = z^T(2\sum_{k=1}^{n}\Phi(x_k)\Phi(x_k)^T)z = 2\sum_{k=1}^{n}z^T\Phi(x_k)\Phi(x_k)^Tz
$$

Analizando cada término individualmente tenemos:

$$
z^T\Phi(x_k)\Phi(x_k)^Tz
=
((z^T\Phi(x_k))^T)^T(\Phi(x_k)^Tz)
=
(\Phi(x_k)^Tz)^T(\Phi(x_k)^Tz)
=
(\Phi(x_k)^Tz)^2 \geq 0
$$

Luego $2\sum_{k=1}^{n}(\Phi(x_k)^Tz)^2 \geq 0$ y por tanto H es semidefinida positiva.

Como la Hessiana de $S(c)$ es semidefinida positiva, $S(c)$ es una función convexa. $\square$

Al ser $S(c)$ una función convexa basta con encontrar un punto $c*$ donde $\nabla S(c*) = 0$.

Para esto tenemos que igualar la $i$-ésima componente del vector gradiente a 0:

$$
\frac{\partial S(c)}{\partial c_i} = -2 \sum_{k=1}^{n} f_i(x_k) \left(y_k - \sum_{j=1}^{m} c_jf_j(x_k) \right) = -2 \sum_{k=1}^{n} \left(y_k f_i(x_k) - \sum_{j=1}^{m}c_jf_i(x_k)f_j(x_k) \right) = 0
$$

Simplificando y despejando se tiene

$$
\sum_{k=1}^{n}\sum_{j=1}^{m}c_jf_i(x_k)f_j(x_k) = \sum_{k=1}^{n} y_k f_i(x_k)
$$

$$
\sum_{j=1}^{m}\sum_{k=1}^{n} \left( f_i(x_k)f_j(x_k) \right) c_j = \sum_{k=1}^{n} y_k f_i(x_k)
$$

Si hacemos $a_{ij} = \sum_{k=1}^{n}  f_i(x_k)f_j(x_k)$ y $b_i = \sum_{k=1}^{n} y_k f_i(x_k)$ tenemos $m$ ecuaciones que conforman el sistema de ecuaciones lineales $Ac=b$.

## Algoritmo

El algoritmo para resolver este problema, queda reducido a confeccionar la matriz $A$ y el vector $b$ y resolver el sistema de ecucaciones lineales. El pseudocódigo sería el siguiente:

```
minimosCuadrados(x[], y[], f[], n, m)
  Sea A una matriz m x m
  Sea b un vector de tamaño m
  Para todo i en [1,m]:
    Para todo j en [1, m]:
      a[i][j] = sum(x.map(xk => f[i](xk)*f[j](x_k)))
    b[i] = sum(x.map(xk => f[i](xk) * y[i]))
  return solucionSistema(A, b)
```

Se asume que se tiene un método `solucionSistema(A, b)` que devuelve el vector solucion de un sistema de ecuaciones lineales o un mensaje de error en caso de que no sea compatible determinado.
La complejidad de este algoritmo sería $O(nm^2 + q)$ donde $q$ es la complejidad del método `solucionSistema(A, b)`.
