import java.io.*; 
import java.util.*; 

class DFS { 
    private int V;   // 정점의 개수
    private LinkedList<Integer> adj[]; // 인접 리스트
    
    // 지시자
    @SuppressWarnings("unchecked")
	public DFS(int v){ 
        V = v; 
        adj = new LinkedList[v]; 
        for (int i=0; i<v; ++i) 
            adj[i] = new LinkedList(); // 초기화
    } 
  
    // 간선 추가 함수
    void addEdge(int v, int w) { 
        adj[v].add(w);  // v 리스트에 w 추가
        //System.out.println("노드 "+v+"에 "+w+"추가 "+adj[v].toString());
    } 
  
    // A function used by DFS 
    void DFSUtil(int v,boolean visited[])  { 
        // 현재 노드를 방문한 것으로 표시한 뒤, 출력
        visited[v] = true;        // 방문 true
        System.out.print(v+" ");  
  
        // 이 정점에 인접한 모든 정점에 대해 반복
        Iterator<Integer> i = adj[v].listIterator(); 
        while (i.hasNext()) { 
            int n = i.next(); 
            if (!visited[n]) // false면 방문 표시
                DFSUtil(n, visited); 
        } 
    } 
  
    void DFS(int v) { 
        
        boolean visited[] = new boolean[V]; // 모든 정점을 방문하지 않은 것으로 표시 (Java에서 기본적으로 false로 설정) 
        DFSUtil(v, visited); // 재귀 함수를 호출하여 DFS 순회 출력
    } 
  
    public static void main(String args[]) 
    { 
    	DFS g = new DFS(4); 
    	  
        g.addEdge(0, 1); 
        g.addEdge(0, 2); 
        g.addEdge(1, 2); 
        g.addEdge(2, 0); 
        g.addEdge(2, 3); 
        g.addEdge(3, 3); 
  
        System.out.println("시작 정점 2"); 
  
        g.DFS(2); 
    } 
} 
