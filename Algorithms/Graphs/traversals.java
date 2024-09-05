package Algorithms.Graphs;

import java.util.*;

class Traversals<T> {
    private Map<T, List<T>> adjVertices;

    public Traversals() {
        this.adjVertices = new HashMap<>();
    }

    public void addVertex(T vertex) {
        adjVertices.putIfAbsent(vertex, new ArrayList<>());
    }

    public void addEdge(T src, T dest) {
        adjVertices.get(src).add(dest);
    }

    /*  Breadth First Search 
     * ----------------------
     * Space Complexity: O(V + E)
     * Time Complexity: O(V + E)
     * Iterates over vertices level by level through the graph, and marks each vertex as visited as it is 
     * traversed. Uses a queue to keep track of the vertices.
    */

    public void BFS(T start) {
        Queue<T> q = new LinkedList<>();
        Set<T> visited = new HashSet<>();
        q.add(start);
        visited.add(start);
        while (!q.isEmpty()) {
            T vertex = q.poll();
            System.out.println(vertex + " ");
            for (T v: adjVertices.get(vertex)) {
                if (!visited.contains(v)) {
                    visited.add(v);
                    q.add(v);
                }
            }
        }
    }

    /* Depth First Search
     * ------------------
     * Space Complexity: O(V + E)
     * Time Complexity: O(V + E)
     * Iterates over vertices as far as possible through the graph, and marks each vertex as visited as it is
     * traversed. Uses a stack to keep track of the vertices.
     */
    public void DFS(T start) {
        Stack<T> s = new Stack<>();
        Set<T> visited = new HashSet<>();
        s.push(start);
        visited.add(start);
        while (!s.isEmpty()) {
            T vertex = s.pop();
            System.out.println(vertex + " ");
            for (T v: adjVertices.get(vertex)) {
                if (!visited.contains(v)) {
                    visited.add(v);
                    s.push(v);
                }
            }
        }
    }

    /* Topological Sort 
     * ----------------
     * Space Complexity: O(V + E)
     * Time Complexity: O(V + E)
     * Sorts the vertices in a directed acyclic graph such that for every directed edge uv from vertex u to vertex v,
     * u comes before v in the ordering. Uses a stack to keep track of the vertices (Similar to DFS).
     */
    public void topologicalSort(T start) {
        Stack<T> s = new Stack<>();
        Set<T> visited = new HashSet<>();
        s.push(start);
        visited.add(start);
        while (!s.isEmpty()) {
            T vertex = s.pop();
            System.out.println(vertex + " ");
            for (T v:adjVertices.get(vertex)) {
                if (!visited.contains(v)) {
                    visited.add(v);
                    s.push(v);
                }
            }
        }
    }
    
    public static void main(String[] args) {
        Traversals<Integer> g = new Traversals<>();
        g.addVertex(1);
        g.addVertex(2);
        g.addVertex(3);
        g.addVertex(4);
        g.addEdge(1, 2);
        g.addEdge(2, 3);
        g.addEdge(3, 1);
        g.addEdge(4, 4);
        g.BFS(2);
        System.out.println();
        g.DFS(3);
        System.out.println();
        g.topologicalSort(1);
    }
}
