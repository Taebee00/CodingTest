<aside>
π‘ κ·Έλν

</aside>

- μ μ κ³Ό κ°μ μΌλ‘ μ΄λ£¨μ΄μ§ μ§ν©
- μ μ μ λ³΄ν΅ $u, v$λ±μΌλ‘ νννκ³  κ°μ μ $e$λ‘ ννν¨

![](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/78509e5a-66a1-4871-8b35-981af95f3b0a/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20230310%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20230310T142305Z&X-Amz-Expires=86400&X-Amz-Signature=04607532851b89aac29e731a51dcb2323ed7d04ba6ba5af51c0ff89073b18ccd&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22Untitled.png%22&x-id=GetObject)

---

<aside>
π‘ νΈλ¦¬

</aside>

- κ³μΈ΅μ μΈ κ΅¬μ‘°λ₯Ό κ°μ§ κ·Έλνμ μΌμ’
- μ¬μ΄ν΄μ΄ μ‘΄μ¬νμ§ μμ
- κ°μ  μ($e$) = λΈλ μ ($v$)-1

![](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/62c65847-04d0-4d64-992a-b21cb65b1f9c/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20230310%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20230310T142344Z&X-Amz-Expires=86400&X-Amz-Signature=6453a0a9c51e7ec54a6b7a4c5ae17ab959e05f439eefbe34b1e90cd4949d7b90&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22Untitled.png%22&x-id=GetObject)

---

<aside>
π‘ μ΄μ§νμνΈλ¦¬(BST)

</aside>

- μ΄μ§νΈλ¦¬μ μΌμ’μΌλ‘ λΈλμ μ€λ₯Έμͺ½μ νμ νΈλ¦¬μλ `λΈλμ κ°λλ€ ν° κ°`, μΌμͺ½ νμνΈλ¦¬μλ `λΈλμ κ°λ³΄λ€ μμ κ°`μ΄ λ€μ΄κ° μλ νΈλ¦¬
- μ΄μ§νμνΈλ¦¬μ μκ°λ³΅μ‘λλ νμ, μ½μ, μ­μ , μμ  λͺ¨λ $O(logN)$

![μ΄μ§νμνΈλ¦¬μ κ΅¬μ‘°](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/f96a7f3c-7849-451a-87c2-08e86606f985/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20230310%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20230310T142452Z&X-Amz-Expires=86400&X-Amz-Signature=58718f538683996f7c1514bf8ad027a01a98e6873beb15f9782b62b39c3d7911&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22Untitled.png%22&x-id=GetObject)

---

<aside>
π‘ κ·Έλν κ΅¬νκ³Ό νμ 1 - μΈμ νλ ¬

</aside>

- μ μ κ³Ό κ°μ μ κ΄κ³λ₯Ό λνλ΄λ bool νμμ μ μ¬κ°ν νλ ¬

![κ·Έλνμ κ΅¬μ‘°](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/220a1596-1dbe-4b88-87f9-c53e1575130b/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20230310%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20230310T142517Z&X-Amz-Expires=86400&X-Amz-Signature=eef5e0608653ebf35b0ee0f2e97867e7e16c09a0e6c7ba9316fb7a560e8da497&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22Untitled.png%22&x-id=GetObject)

```cpp
bool a[4][4] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 0},
    {1, 0, 0, 0},
};

```

---

<aside>
π‘ κ·Έλν κ΅¬νκ³Ό νμ 2 - μΈμ λ¦¬μ€νΈ

</aside>

- μ μ κ³Ό κ°μ μ κ΄κ³λ₯Ό λνλ΄λ μ°κ²°λ¦¬μ€νΈ

![κ·Έλνμ κ΅¬μ‘°](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/220a1596-1dbe-4b88-87f9-c53e1575130b/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20230310%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20230310T142517Z&X-Amz-Expires=86400&X-Amz-Signature=eef5e0608653ebf35b0ee0f2e97867e7e16c09a0e6c7ba9316fb7a560e8da497&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22Untitled.png%22&x-id=GetObject)

![κ·Έλνλ₯Ό μ°κ²°λ¦¬μ€νΈλ‘ νν](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/3aebd5ff-8f46-402b-b63b-eb374b3dd6f4/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20230310%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20230310T142550Z&X-Amz-Expires=86400&X-Amz-Signature=e240320dbf4bfc0d425af9c457d5538a7eab8c86ad1a14c8ef46a514656a4e5a&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22Untitled.png%22&x-id=GetObject)

```cpp
const int V = 4;
vector<int> adj[V];
int maμ
```

---

<aside>
π‘ μΈμ λ¦¬μ€νΈμ μΈμ νλ ¬μ μ°¨μ΄

</aside>

- κ³΅κ°λ³΅μ‘λ
    - μΈμ νλ ¬: $O(V^2)$
    - μΈμ λ¦¬μ€νΈ: $O(V+E)$
- μκ°λ³΅μ‘λ: κ°μ  νκ° μ°ΎκΈ°
    - μΈμ νλ ¬: $O(1)$
    - μΈμ λ¦¬μ€νΈ: $O(V)$
- μκ°λ³΅μ‘λ: λͺ¨λ  κ°μ  μ°ΎκΈ°
    - μΈμ νλ ¬: $O(V^2)$
    - μΈμ λ¦¬μ€νΈ: $O(V+E)$
- λ°λΌμ κ·Έλνκ° ν¬μν  λλ μΈμ λ¦¬μ€νΈ, μ‘°λ°ν  λλ μΈμ νλ ¬μ΄ μ λ¦¬ν¨

---

<aside>
π‘ κ·Έλν κ΅¬νκ³Ό νμ 3 - λ§΅κ³Ό λ°©ν₯λ²‘ν°

</aside>

- μΈμ νλ ¬μ΄λ μΈμ λ¦¬μ€νΈλ‘ λ¬Έμ κ° μ£Όμ΄μ§λ κ² μλ μλμ κ·Έλ¦Όμ²λΌ λ§΅μΌλ‘ μ£Όμ΄μ§λ μν©μ΄ μ‘΄μ¬
    
    ![λ§΅μΌλ‘ μ£Όμ΄μ§λ λ¬Έμ ](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/8f92c582-dbf9-496f-b8d2-2f3df33e02a7/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20230310%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20230310T142619Z&X-Amz-Expires=86400&X-Amz-Signature=0358e2cb9d53efea0be8eaf80b6ed92da073cb6e699fb11cb593f5ec05dde7ed&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22Untitled.png%22&x-id=GetObject)
    
- λ³΄ν΅ μ΄λ° λ§΅μ νμ¬ μμΉ κΈ°μ€ μ,ν,μ’,μ° νμμ΄ κ°λ₯
    - λ°°μ΄μ ν΅ν΄ κ°λ¨ν νμ κ°λ₯
    
    ```cpp
    const int dy[] = {-1, 0, 1, 0};
    const int dx[] = {0, 1, 0, -1};
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
    }
    ```
    

---

<aside>
π‘ κΉμ΄μ°μ νμ [DFS]

</aside>

- κ·Έλνλ₯Ό νμν  λ μ¬κ·μ μΌλ‘ λ°©λ¬Ένμ¬ κ° λΆκΈ°λ§λ€ κ°μ₯ λ©λ¦¬ μλ λΈλκΉμ§ νμνλ μκ³ λ¦¬μ¦
- κ΅¬ν λ°©λ² 1
    
    ```cpp
    void dfs(int here){
        visited[here] = 1; 
        for(int there : adj[here]){
            if(visited[there]) continue;
            dfs(there);
        }
    }
    ```
    
    - λ°©λ¬Έ λ°°μ΄`vistied` μ λΈλ`here` λ°©λ¬Έ νμ
    - `here`κ³Ό μΈμ ν λΈλλ₯Ό λλ©°, λ°©λ¬Έν λΈλκ° μλλΌλ©΄ μΈμ ν λΈλμ λν μ¬κ·ν¨μ νΈμΆ
- κ΅¬ν λ°©λ² 2
    
    ```cpp
    void dfs(int here){
        visited[here] = 1; 
        for(int there : adj[here]){
            if(visited[there]) continue;
            dfs(there);
        }
    }
    ```
    
    - `here`λΈλλ₯Ό λ°©λ¬Ένλ€λ©΄ `return`
    - μλλΌλ©΄ λ°©λ¬Έ λ°°μ΄`vistied`μ λΈλ `here` λ°©λ¬Έ νμ
    - `here`κ³Ό μΈμ ν λΈλλ₯Ό λλ©°, λ°©λ¬Έν λΈλκ° μλλΌλ©΄ μΈμ ν λΈλμ λν μ¬κ·ν¨μ νΈμΆ
    

---

<aside>
π‘ λλΉμ°μ νμ

</aside>

- κ·Έλνλ₯Ό νμν  λ, λ€μ κΉμ΄μ μ μ μΌλ‘ μ΄λνκΈ° μ  νμ¬ κΉμ΄μ λͺ¨λ  μ μ μ λͺ¨λ λ°©λ¬Ένμ¬ νμν ν μ΄λνλ μκ³ λ¦¬μ¦
- κ°μ κ°μ€μΉλ₯Ό κ°μ§ κ·Έλνμμ μ΅λ¨ κ±°λ¦¬λ₯Ό κ΅¬ν  μ μμ
- κ΅¬ν λ°©λ²
    
    ```cpp
    void bfs(int here){
        queue<int> q; 
        visited[here] = 1; 
        q.push(here);
        while(q.size()){
            int here = q.front(); q.pop();
            for(int there : adj[here]){
                if(visited[there]) continue;
                visited[there] = visited[here] + 1;
                q.push(there);
            }
        }
    }
    ```
    
    - λ°©λ¬Έ μμλ₯Ό μ‘°μ¨ν  ν `q` μμ±
    - λ°©λ¬Έλ°°μ΄μΈ `visited`μ μμλΈλμΈ `here` λ°©λ¬Έ νμ
    - `q` μ μμλΈλμΈ `here`μ `push()`
    - `q`μ μ¬μ΄μ¦κ° 0μ΄ λ  λκΉμ§ λ°λ³΅
        - `here`μ νμ¬ `q`μ κ°μ₯ μ `front()`λ₯Ό μ μ₯νκ³  `pop()`
        - `here`κ³Ό μΈμ ν λΈλλ₯Ό λλ©° λ°©λ¬Ένμ§ μμ μΈμ ν λΈλ `there`μ΄ μλ€λ©΄ `visited[there]`μ `visited[here]+1`κ°μ λ£μ΄μ€
            - μμλΈλμμ κ° λΈλκΉμ§μ μ΅μ κ±°λ¦¬κ° κ° λΈλμ `visitied` λ°°μ΄μ μΆκ°λ¨
        - `there`μ `q`μ `push()`

---

<aside>
π‘ DFS - BFS λΉκ΅

</aside>

- DFS: λ©λͺ¨λ¦¬λ₯Ό λ μ¬μ©, μ½λκ° μ’ λ μ§§μΌλ©° μμ νμμ κ²½μ°μ λ§μ΄ μ¬μ©
- BFS: λ©λͺ¨λ¦¬λ₯Ό λ μ¬μ©, μ½λκ° μ’ λ κΈΈλ©° κ·Έλνλ΄μμμ μ΅λ¨κ±°λ¦¬λ₯Ό κ΅¬ν  λ λ§μ΄ μ¬μ©

---

<aside>
π‘ νΈλ¦¬μν

</aside>

- νμμν
    - μμλΈλλ₯Ό λ¨Όμ  λ°©λ¬Ένκ³  μμ μ λΈλλ₯Ό λ°©λ¬Έ
    
    ```cpp
    postorder( node )
        if (node.visited == false) 
            postorder( node->left ) 
            postorder( node->right )
            node.visited = true
    ```
    
- μ μμν
    - μμ μ λΈλλ₯Ό λ°©λ¬Ένκ³  κ·Έ λ€μ μμ λΈλ λ°©λ¬Έ
    
    ```cpp
    preorder( node )
        if (node.visited == false)
            node.visited = true
            preorder( node->left )
            preorder( node->right )
    ```
    
- μ€μμν
    - μΌμͺ½ λΈλ, μμ μ λΈλ, μ€λ₯Έμͺ½ λΈλ μμΌλ‘ λ°©λ¬Έ
    
    ```cpp
    inorder( node )
        if (node.visited == false) 
            inorder( node->left )
            node.visited = true
            inorder( node->right )
    ```
    

---