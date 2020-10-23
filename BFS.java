import java.io.*; 
import java.util.*; 
  

class BFS { 
    private int V;   // 정점의 개수 
    private LinkedList<Integer> adj[]; // 인접 리스트 
  
    public BFS(int v) { 
        V = v; 
        adj = new LinkedList[v]; 
        for (int i=0; i<v; ++i) 
            adj[i] = new LinkedList(); 
    } 

    void addEdge(int v,int w){ // 간선 추가
        adj[v].add(w); 
    } 
  
    void BFS(int s) { 

        boolean visited[] = new boolean[V]; 
        LinkedList<Integer> queue = new LinkedList<Integer>(); // 큐 생성
  
        // 현재 노드를 방문한 것으로 표시하고 큐에 추가
        visited[s]=true; 
        queue.add(s); 
  
        while (queue.size() != 0) 
        { 
            // 대기열에서 정점을 제거하고 출력
            s = queue.poll();          
            System.out.print(s+" ");

             // 큐에서 제외 된 정점의 모든 인접 정점을 가져옴
             // 인접 정점을 방문하지 않은 경우 표시
             // 방문하여 큐에 추가
            Iterator<Integer> i = adj[s].listIterator(); 
            while (i.hasNext()) 
            { 
                int n = i.next(); 
                if (!visited[n]) 
                { 
                    visited[n] = true; 
                    queue.add(n); 
                } 
            } 
        } 
    } 
  
    public static void main(String args[]) 
    { 
        BFS g = new BFS(4); 
  
        g.addEdge(0, 1); 
        g.addEdge(0, 2); 
        g.addEdge(1, 2); 
        g.addEdge(2, 0); 
        g.addEdge(2, 3); 
        g.addEdge(3, 3); 
  
        System.out.println("시작 정점 2"); 
  
        g.BFS(2); 
    } 
} 
