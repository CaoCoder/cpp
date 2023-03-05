//
//#include<iostream>
//#include<queue>
//#include<cstring>
//using namespace std;
//const int N = 405;
//struct node {
//    int x, y, step;
//};
//
//queue<node> q;
//int n, m, x0, y0, a[N][N];
//int vis[N][N];
//int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
//int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };
//
//bool isvalid(int x, int y)
//{
//    return x >= 1 && x <= n && y >= 1 && y <= m && vis[x][y] == 0;
//}
//void bfs()
//{
//
//    node start;
//    a[x0][y0] = 0;
//    start.step = 0;
//    start.x = x0;
//    start.y = y0;
//    vis[x0][y0] = 1;
//    q.push(start);
//    while (!q.empty())
//    {
//        node t = q.front();
//        for (int i = 0; i < 8; i++)
//        {
//            int tx = t.x + dx[i];
//            int ty = t.y + dy[i];
//            if (isvalid(tx, ty))
//            {
//                a[tx][ty] = t.step + 1;
//                node temp;
//                temp.x = tx;
//                temp.y = ty;
//                temp.step = t.step + 1;
//                q.push(temp);
//                vis[tx][ty] = 1;
//            }
//        }
//        q.pop();
//    }
//}
//int main()
//{
//    cin >> n >> m >> x0 >> y0;
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            a[i][j] = -1;
//        }
//    }
//    bfs();
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; i <= m; j++)
//        {
//            cout << a[i][j] << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}
