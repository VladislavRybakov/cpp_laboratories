#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <ctime>

#define TICK(X) clock_t X = clock() // в переменную Х кладем начальное время
#define TOCK(X) printf("Time: %g sec.\n", (double)(clock() - (X)) / CLOCKS_PER_SEC)

const int n = 500;

int* podprogramm(int a[], int p);
void mini_programm(int a[], int b[], int first, int last);

int main()
{
  srand(time(0));

  int *a = new int[n];
  for (int i = 0; i < n; i++) {
    a[i] = rand() % 100;
  }
  int* b = NULL;

  unsigned int nthreads = std::thread::hardware_concurrency();

  for (int i = 1; i <= nthreads; i++) {
    std::cout << "With " << i << " threads: ";
    TICK(time);
    b = podprogramm(a, i);
    TOCK(time);
  }
  std::cout << '\n';

  std::cout << "Before my programm: \n";
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << ' ';
  }
  std::cout << "\n\nAfter my programm:\n";
  for (int i = 0; i < n; i++) {
    std::cout << b[i] << ' ';
  }
  std::cout << '\n';

  delete [] a, b;
}

int* podprogramm(int a[], int p) {
  std::vector<std::thread> thread_vec(p);
  int *b = new int[n];
  
  if (p == 0) {
    mini_programm(a, b, 0, n - 1);
    return b;
  }

  int line = n / p;

  for (int i = 0; i < p; i++) {
    if (i == p - 1) {
      thread_vec[i] = std::thread(mini_programm, a, b, i * line, n-1);
      break;
    }
    thread_vec[i] = std::thread(mini_programm,a, b, i * line, (i + 1) * line - 1);
  }
  for (int i = 0; i < p; i++) {
    thread_vec[i].join();
  }

  return b;
}

void mini_programm(int a[], int b[], int first, int last) {
  for (int i = first; i <= last; i++) {
    if (i == 0) {
      b[i] = (a[n-1] + a[i + 1]) / 2;
    }
    else if(i == n-1) {
      b[i] = (a[i - 1] + a[0]) / 2;
    }
    else {
      b[i] = (a[i - 1] + a[i + 1]) / 2;
    }
  }
}
