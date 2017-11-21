#include <stdio.h>
#include <stdlib.h>
//#include <signal.h>
//#include <fcntl.h>
#include <unistd.h>

int main() {
  int READ = 0;
  int WRITE = 1;

  int to_child[2];
  pipe(to_child);

  int to_parent[2];
  pipe(to_parent);

  if (fork()) {
    int n = 167;
    int m;

    printf("PARENT: sending %d\n", n);
    close(to_child[READ]);
    write(to_child[WRITE], &n, sizeof(n));
    close(to_child[WRITE]);

    close(to_parent[WRITE]);
    read(to_parent[READ], &m, sizeof(m));
    close(to_parent[READ]);
    printf("PARENT: received %d\n", m);
  } else {
    int n;
    int m;

    close(to_child[WRITE]);
    read(to_child[READ], &n, sizeof(n));
    close(to_child[READ]);

    printf("CHILD: mathing %d\n", n);
    m = n / 10;

    close(to_parent[READ]);
    write(to_parent[WRITE], &m, sizeof(m));
    close(to_parent[WRITE]);
  }



  return 0;
}
