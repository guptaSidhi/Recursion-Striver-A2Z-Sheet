bool safe(int c,int node,bool graph[101][101],int m,int n,int col[]){
       for(int i = 0;i<n;i++){
           if( graph[i][node] == 1 and col[i] == c) return 0;
       }
        return 1;
    }
    bool solve(int node,bool graph[101][101],int m,int n,int col[]){
        if(node == n){
            return 1;
        }
        for(int i = 1;i<=m;i++){
            if(safe(i,node,graph,m,n,col)){
                col[node] = i;
                if(solve(node+1,graph,m,n,col)) return true;
                col[node] = 0;
            }
        }
        return 0;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        int col[n] = {0};
        if(solve(0,graph,m,n,col)) return 1;
        return 0;
    }