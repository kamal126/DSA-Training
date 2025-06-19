🔷 Function: DFS(...)
>void DFS(int node, int parent, vector<int> adj[], vector<bool>& visited, vector<vector<int>>& Bridges, vector<int>& low, vector<int>& disc, int count)</code>

DFS (Depth-First Search) function hai jo graph traverse karta hai aur bridge edges ko identify karta hai. Parameters:

node: current node jisme DFS chal rahi hai.
parent: jahan se current node aayi hai (i.e., parent in DFS tree).
adj[]: adjacency list (graph).
visited[]: check karta hai node visit hua ya nahi.
Bridges: bridges ko store karta hai.
low[]: lowest discovery time reachable from subtree.
disc[]: discovery time of each node.
count: DFS time step (important in Tarjan's algorithm).

🔹 Inside DFS
<code>
>low[node] = disc[node] = count;</code>
disc[node]: Discovery time jab node visit hua.

low[node]: Lowest discovery time reachable from node (including back edges).

visited[node] = 1;
Node ko visited mark kiya.

🔁 Traversing Neighbours
for (auto& neighbour : adj[node]) {
Har adjacent node (neighbour) ke liye DFS lagate hain.

if (neighbour == parent) continue;
Agar neighbour parent hai (jahan se aaye the), to ignore karo. Kyunki undirected graph mein parent bhi neighbour hota hai.

🔄 Already Visited Case

if (visited[neighbour]) {
    low[node] = min(low[node], low[neighbour]);
}
Agar neighbour pehle se visited hai, to ek back edge mila.

low[node] ko update karo to reflect ki woh node cycle se kisi pehle node tak pahuch sakta hai.

🔄 Not Yet Visited Case (Main DFS Call)

else {
    count++;
    DFS(neighbour, node, adj, visited, Bridges, low, disc, count);
Agar neighbour visited nahi hai, to DFS lagao neighbour pe.

count++: next discovery time pass kiya (❗but ye galat hai ― reference hona chahiye).


if (disc[node] < low[neighbour]) {
    Bridges.push_back({node, neighbour});
}
Agar low[neighbour] > disc[node], iska matlab:

Neighbour kisi ancestor node tak back edge se pahuch nahi sakta.

Iska matlab edge (node - neighbour) bridge hai.


low[node] = min(low[node], low[neighbour]);
DFS ke baad low value ko update karo to reflect subtree reachability.

🔷 Main Function: criticalConnections(...)

vector<int> adj[n];
Graph ka adjacency list banaya.


for (auto& edge : connections) {
    int u = edge[0];
    int v = edge[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
}
Connections ko graph mein daala (undirected edge ― dono direction mein).

vector<bool> visited(n, 0);
vector<vector<int>> Bridges;
vector<int> low(n, 0);
vector<int> disc(n, 0);
int count = 0;
Helper arrays banaye: visited, low time, discovery time.

Bridges: final result.

count: DFS timing tracker.


for (int i = 0; i < n; i++) {
    if (!visited[i])
        DFS(0, -1, adj, visited, Bridges, low, disc, count);
}
Graph ke har node ke liye DFS chalaate hain agar visited nahi hai.

Hamesha DFS(0, ...) likha hai ― ye galat hai. Ye hona chahiye:

DFS(i, -1, adj, visited, Bridges, low, disc, count);
🔚 Return bridges

return Bridges;

⚠️ Summary of Issues (Jo fix karni chahiye):
Issue	Explanation	Fix
count passed by value	Har recursion mein count reset ho jaata hai	Pass count by reference (int& count)
DFS always starts from node 0	Har bar sirf 0 se DFS chal raha hai	Use DFS(i, ...)
vector<int> adj[n]	Valid only in local scope if n known	Use vector<vector<int>> adj(n)
low[neighbour] in back edge	Use disc[neighbour] not low[neighbour]	Minor but affects correctness in some cases

