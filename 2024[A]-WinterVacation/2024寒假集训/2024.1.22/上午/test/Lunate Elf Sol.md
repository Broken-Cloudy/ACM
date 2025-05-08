## 题解

$\min$ 和 $+$ 满足以下运算律：

- 交换律：$\min(a,b)=\min(b,a),a+b=b+a$
- 结合律：$\min(\min(a,b),c)=\min(a,\min(b,c)),(a+b)+c=a+(b+c)$
- 单位元：$\min(+\infty,a)=\min(a,+\infty)=a,a+0=0+a=a$
- 分配律：$\min(a,b)+c=\min(a+c,b+c),a+\min(b,c)=\min(a+b,a+c)$

因此，将 $\min$ 作为矩阵元素的加法，$+$ 作为矩阵元素的乘法：

$$(A+B)_{i,j}=\min(A_{i,j},B_{i,j}),(AB)_{i,j}=\min_{k}(A_{i,k}+B_{k,j}）$$

则矩阵的加法一样满足交换律、结合律，存在单位元（零矩阵）；  
矩阵的乘法一样满足结合律，存在单位元（单位矩阵），且对矩阵加法满足分配律。

因此，对数列 $a,b$ 的操作可用矩阵来描述：

- 1 操作： $\displaystyle\forall k\in[l,r],{a_k\brack b_k}\leftarrow\begin{bmatrix}c&+\infty\\+\infty&0\end{bmatrix}{a_k\brack b_k}$
- 2 和 3 操作： 求 $\displaystyle{a_l\brack b_l}+{a_{l+1}\brack b_{l+1}}+\cdots+{a_r\brack b_r}$

每次操作后 $\displaystyle\forall k\in[1,n],{a_k\brack b_k}\leftarrow\begin{bmatrix}0&+\infty\\0&0\end{bmatrix}{a_k\brack b_k}$


线段树上维护 向量之和 与 矩阵乘法标记 即可。

更详细的讨论详见 [题解 P6242 【模板】线段树 3](https://www.luogu.com.cn/blog/wangrx/ji-seg-tree) 。
