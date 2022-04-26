#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, s = 1, un = 0, uk = 0, a[502][502], c_x, c_y, x, y;
  int q[250000 ][2];
  freopen("base.in", "r", stdin);
  freopen("base.out", "w", stdout);
  cin >> n >> m;

  // Защитный слой
  for (int i = 0; i < n + 2; i++)
  {
    a[i][0] = a[i][m+1] = -1;
  }

  for (int j = 0; j < m + 2; j++)
  {
    a[0][j] = a[n+1][j] = -1;
  }

  char c;

  // Заполнение поля и проверка на значение
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      cin >> c;
      if (c == '.')
      {
        a[i][j] = -1;
      }

      else
      {
        a[i][j] = 0;
      }
    }
  }

  x = y = 1;

  while (true)
  {
    while (a[x][y] != 0)
    {
      y++;
      if (y == m + 1)
      {
        x++;
        y = 1;
        if (x == n + 1)
        {
          cout << s - 1;
          fclose(stdin);
          fclose(stdout);
          return 0;
        }
      }
    }
    q[uk][0] = x;
    q[uk][1] = y;
    uk++;
    a[x][y] = s;
    while (uk != un)
    {
      c_x = q[un][0];
      c_y = q[un][1];
      un++;
      if (a[c_x + 1][c_y] == 0)
      {
        a[c_x + 1][c_y] = s;
        q[uk][0] = c_x + 1;
        q[uk][1] = c_y;
        uk++;
      }

      if (a[c_x - 1][c_y] == 0)
      {
        a[c_x - 1][c_y] = s;
        q[uk][0] = c_x - 1;
        q[uk][1] = c_y;
        uk++;
      }

      if (a[c_x][c_y + 1] == 0)
      {
        a[c_x][c_y + 1] = s;
        q[uk][0] = c_x;
        q[uk][1] = c_y + 1;
        uk++;
      }

      if (a[c_x][c_y - 1] == 0)
      {
        a[c_x][c_y - 1] = s;
        q[uk][0] = c_x;
        q[uk][1] = c_y - 1;
        uk++;
      }
    }
    s++;
  }
}
