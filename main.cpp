#include <bits/stdc++.h>
using namespace std;

int main()
{
  int m, n, k, s = 1, un = 0, uk = 0, a[102][102], q[10000][2], c_x, c_y;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  cin >> m >> n;
  cin >> k;
  // Защитный слой
  for (int i = 0; i < n + 2; i++)
  {
    a[i][0] = a[i][m + 1] = -1;
  }

  for (int j = 0; j < m + 2; j++)
  {
    a[0][j] = a[n + 1][j] = -1;
  }

  // Заполнение нулями
  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j < m + 1; j++)
    {
      a[i][j] = 0;
    }
  }

  // Ввод координат и отметка
  int x, y;
  for (int i = 0; i < k; i++)
  {
    cin >> x >> y;
    a[x][y] = -1;
  }

  x = y = 1;

  // Исследование
  while (0 == 0)
  {
    while (a[x][y] != 0)
    {
      y++;
      if (y == m + 1)
      {
        y = 1;
        x++;
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


