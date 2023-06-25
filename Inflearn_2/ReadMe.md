<h3>
💡 그래프

</h3>

- 정점과 간선으로 이루어진 집합
- 정점은 보통 $u, v$등으로 표현하고 간선은 $e$로 표현함

![](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/78509e5a-66a1-4871-8b35-981af95f3b0a/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20230310%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20230310T142305Z&X-Amz-Expires=86400&X-Amz-Signature=04607532851b89aac29e731a51dcb2323ed7d04ba6ba5af51c0ff89073b18ccd&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22Untitled.png%22&x-id=GetObject)

---

<h3>
💡 트리

</h3>

- 계층적인 구조를 가진 그래프의 일종
- 사이클이 존재하지 않음
- 간선 수($e$) = 노드 수 ($v$)-1

![](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/62c65847-04d0-4d64-992a-b21cb65b1f9c/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20230310%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20230310T142344Z&X-Amz-Expires=86400&X-Amz-Signature=6453a0a9c51e7ec54a6b7a4c5ae17ab959e05f439eefbe34b1e90cd4949d7b90&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22Untitled.png%22&x-id=GetObject)

---

<h3>
💡 이진탐색트리(BST)

</h3>

- 이진트리의 일종으로 노드의 오른쪽의 하위 트리에는 `노드의 값도다 큰 값`, 왼쪽 하위트리에는 `노드의 값보다 작은 값`이 들어가 있는 트리
- 이진탐색트리의 시간복잡도는 탐색, 삽입, 삭제, 수정 모두 $O(logN)$

![이진탐색트리의 구조](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/f96a7f3c-7849-451a-87c2-08e86606f985/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20230310%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20230310T142452Z&X-Amz-Expires=86400&X-Amz-Signature=58718f538683996f7c1514bf8ad027a01a98e6873beb15f9782b62b39c3d7911&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22Untitled.png%22&x-id=GetObject)

---

<h3>
💡 그래프 구현과 탐색 1 - 인접행렬

</h3>

- 정점과 간선의 관계를 나타내는 bool 타입의 정사각형 행렬

![그래프의 구조](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/220a1596-1dbe-4b88-87f9-c53e1575130b/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20230310%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20230310T142517Z&X-Amz-Expires=86400&X-Amz-Signature=eef5e0608653ebf35b0ee0f2e97867e7e16c09a0e6c7ba9316fb7a560e8da497&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22Untitled.png%22&x-id=GetObject)

```cpp
bool a[4][4] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 0},
    {1, 0, 0, 0},
};

```

---

<h3>
💡 그래프 구현과 탐색 2 - 인접리스트

</h3>

- 정점과 간선의 관계를 나타내는 연결리스트

![그래프의 구조](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/220a1596-1dbe-4b88-87f9-c53e1575130b/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20230310%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20230310T142517Z&X-Amz-Expires=86400&X-Amz-Signature=eef5e0608653ebf35b0ee0f2e97867e7e16c09a0e6c7ba9316fb7a560e8da497&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22Untitled.png%22&x-id=GetObject)

![그래프를 연결리스트로 표현](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/3aebd5ff-8f46-402b-b63b-eb374b3dd6f4/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20230310%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20230310T142550Z&X-Amz-Expires=86400&X-Amz-Signature=e240320dbf4bfc0d425af9c457d5538a7eab8c86ad1a14c8ef46a514656a4e5a&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22Untitled.png%22&x-id=GetObject)

```cpp
const int V = 4;
vector<int> adj[V];
int ma시
```

---

<h3>
💡 인접리스트와 인접행렬의 차이

</h3>

- 공간복잡도
    - 인접행렬: $O(V^2)$
    - 인접리스트: $O(V+E)$
- 시간복잡도: 간선 한개 찾기
    - 인접행렬: $O(1)$
    - 인접리스트: $O(V)$
- 시간복잡도: 모든 간선 찾기
    - 인접행렬: $O(V^2)$
    - 인접리스트: $O(V+E)$
- 따라서 그래프가 희소할 때는 인접리스트, 조밀할 떄는 인접행렬이 유리함

---

<h3>
💡 그래프 구현과 탐색 3 - 맵과 방향벡터

</h3>

- 인접행렬이나 인접리스트로 문제가 주어지는 게 아닌 아래의 그림처럼 맵으로 주어지는 상황이 존재
    
    ![맵으로 주어지는 문제](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/8f92c582-dbf9-496f-b8d2-2f3df33e02a7/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20230310%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20230310T142619Z&X-Amz-Expires=86400&X-Amz-Signature=0358e2cb9d53efea0be8eaf80b6ed92da073cb6e699fb11cb593f5ec05dde7ed&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22Untitled.png%22&x-id=GetObject)
    
- 보통 이런 맵은 현재 위치 기준 상,하,좌,우 탐색이 가능
    - 배열을 통해 간단히 탐색 가능
    
    ```cpp
    const int dy[] = {-1, 0, 1, 0};
    const int dx[] = {0, 1, 0, -1};
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
    }
    ```
    

---

<h3>
💡 깊이우선탐색 [DFS]

</h3>

- 그래프를 탐색할 때 재귀적으로 방문하여 각 분기마다 가장 멀리 있는 노드까지 탐색하는 알고리즘
- 구현 방법 1
    
    ```cpp
    void dfs(int here){
        visited[here] = 1; 
        for(int there : adj[here]){
            if(visited[there]) continue;
            dfs(there);
        }
    }
    ```
    
    - 방문 배열`vistied` 에 노드`here` 방문 표시
    - `here`과 인접한 노드를 돌며, 방문한 노드가 아니라면 인접한 노드에 대한 재귀함수 호출
- 구현 방법 2
    
    ```cpp
    void dfs(int here){
        visited[here] = 1; 
        for(int there : adj[here]){
            if(visited[there]) continue;
            dfs(there);
        }
    }
    ```
    
    - `here`노드를 방문했다면 `return`
    - 아니라면 방문 배열`vistied`에 노드 `here` 방문 표시
    - `here`과 인접한 노드를 돌며, 방문한 노드가 아니라면 인접한 노드에 대한 재귀함수 호출
    

---

<h3>
💡 너비우선탐색

</h3>

- 그래프를 탐색할 때, 다음 깊이의 정점으로 이동하기 전 현재 깊이의 모든 정점을 모두 방문하여 탐색한 후 이동하는 알고리즘
- 같은 가중치를 가진 그래프에서 최단 거리를 구할 수 있음
- 구현 방법
    
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
    
    - 방문 순서를 조율할 큐 `q` 생성
    - 방문배열인 `visited`에 시작노드인 `here` 방문 표시
    - `q` 에 시작노드인 `here`을 `push()`
    - `q`의 사이즈가 0이 될 때까지 반복
        - `here`에 현재 `q`의 가장 앞 `front()`를 저장하고 `pop()`
        - `here`과 인접한 노드를 돌며 방문하지 않은 인접한 노드 `there`이 있다면 `visited[there]`에 `visited[here]+1`값을 넣어줌
            - 시작노드에서 각 노드까지의 최소 거리가 각 노드의 `visitied` 배열에 추가됨
        - `there`을 `q`에 `push()`

---

<h3>
💡 DFS - BFS 비교

</h3>

- DFS: 메모리를 덜 사용, 코드가 좀 더 짧으며 완전탐색의 경우에 많이 사용
- BFS: 메모리를 더 사용, 코드가 좀 더 길며 그래프내에서의 최단거리를 구할 때 많이 사용

---

<h3>
💡 트리순회

</h3>

- 후위순회
    - 자식노드를 먼저 방문하고 자신의 노드를 방문
    
    ```cpp
    postorder( node )
        if (node.visited == false) 
            postorder( node->left ) 
            postorder( node->right )
            node.visited = true
    ```
    
- 전위순회
    - 자신의 노드를 방문하고 그 다음 자식 노드 방문
    
    ```cpp
    preorder( node )
        if (node.visited == false)
            node.visited = true
            preorder( node->left )
            preorder( node->right )
    ```
    
- 중위순회
    - 왼쪽 노드, 자신의 노드, 오른쪽 노드 순으로 방문
    
    ```cpp
    inorder( node )
        if (node.visited == false) 
            inorder( node->left )
            node.visited = true
            inorder( node->right )
    ```
    

---
