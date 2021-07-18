#include <bits/stdc++.h>
using namespace std;
bool equal(vector<vector<int>> &matrix, int p, int q, int r, int s)
{
    if (matrix[p][q] == matrix[r][s])
        return true;
    return false;
}
bool LR(vector<vector<int>> &matrix, int m, int n)
{
    for (int r = 0; r < m; r++)
    {
        int cl = 0, cr = n - 1;
        while (cl < cr)
        {
            if (equal(matrix, r, cl, r, cr))
            {
                matrix[r][cl] = -1;
                cl++;
                cr--;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
bool RL(vector<vector<int>> &matrix, int m, int n)
{
    for (int r = 0; r < m; r++)
    {
        int cl = 0, cr = n - 1;
        while (cl < cr)
        {
            if (equal(matrix, r, cl, r, cr))
            {
                matrix[r][cr] = -1;
                cl++;
                cr--;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
bool TB(vector<vector<int>> &matrix, int m, int n)
{
    for (int r = 0; r < n; r++)
    {
        int cl = 0, cr = m - 1;
        while (cl < cr)
        {
            if (equal(matrix, r, cl, r, cr))
            {
                matrix[r][cl] = -1;
                cl++;
                cr--;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
bool BT(vector<vector<int>> &matrix, int m, int n)
{
    for (int r = 0; r < n; r++)
    {
        int cl = 0, cr = m - 1;
        while (cl < cr)
        {
            if (equal(matrix, r, cl, r, cr))
            {
                matrix[r][cr] = -1;
                cl++;
                cr--;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
bool TlBr(vector<vector<int>> &matrix, int n)
{
    for (int r = 0; r < n - 1; r++)
    {
        for (int c = 0; c + r < n - 1; c++)
        {
            if (equal(matrix, r, c, n - c - 1, n - r - 1))
            {
                matrix[r][c] = -1;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
bool BrTl(vector<vector<int>> &matrix, int n)
{
    for (int r = 0; r < n - 1; r++)
    {
        for (int c = 0; c + r < n - 1; c++)
        {
            if (equal(matrix, r, c, n - c - 1, n - r - 1))
            {
                matrix[n - c - 1][n - r - 1] = -1;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
bool TrBl(vector<vector<int>> &matrix, int n)
{
    for (int r = 0; r < n - 1; r++)
    {
        for (int c = r + 1; c < n; c++)
        {
            if (equal(matrix, r, c, c, r))
            {
                matrix[r][c] = -1;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
bool BlTr(vector<vector<int>> &matrix, int n)
{
    for (int r = 0; r < n - 1; r++)
    {
        for (int c = r + 1; c < n; c++)
        {
            if (equal(matrix, r, c, c, r))
            {
                matrix[c][r] = -1;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int m, n;
        cin >> m >> n;
        int c, d;
        cin >> c >> d;
        vector<vector<int>> matrix(m);
        for (int i = 0; i < m; i++)
        {
            vector<int> row(n);
            for (int j = 0; j < n; j++)
            {
                cin >> row[j];
            }
            matrix[i] = row;
        }
        bool possible;
        if ((m == 1 && n == 1) || m == 0 || n == 0)
        {
            possible = false;
        }
        else if (c == 1 && d == 3)
        {
            if (m == n)
            {
                possible = TlBr(matrix, n);
            }
            else
            {
                possible = false;
            }
        }
        else if (c == 3 && d == 1)
        {
            if (m == n)
            {
                possible = BrTl(matrix, n);
            }
            else
            {
                possible = false;
            }
        }
        else if (c == 2 && d == 4)
        {
            if (m == n)
            {
                possible = TrBl(matrix, n);
            }
            else
            {
                possible = false;
            }
        }
        else if (c == 4 && d == 2)
        {
            if (m == n)
            {
                possible = BlTr(matrix, n);
            }
            else
            {
                possible = false;
            }
        }
        else if ((c == 1 && d == 4) || (c == 2 && d == 3))
        {
            possible = TB(matrix, m, n);
        }
        else if ((c == 1 && d == 2) || (c == 4 && d == 3))
        {
            possible = LR(matrix, m, n);
        }
        else if ((c == 4 && d == 1) || (c == 3 && d == 2))
        {
            possible = BT(matrix, m, n);
        }
        else
        {
            possible = RL(matrix, m, n);
        }
        cout << t << endl;
        if (!possible)
        {
            cout << "error\n";
        }
        else
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (matrix[i][j] == -1)
                    {
                        cout << '-';
                    }
                    else
                    {
                        cout << matrix[i][j];
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}