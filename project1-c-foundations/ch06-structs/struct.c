#include <stdio.h>
#include <stdlib.h>

/*
  Define a Point struct (int x, y) and a Rect struct with two Point members. Write two functions: one that computes area taking a Rect by value, and one that scales a Rect in-place taking a Rect*.

  Use the dot operator on the value version, the arrow operator on the pointer version
  Print sizeof(Point) and sizeof(Rect)
  In a comment: when would you prefer passing a struct by pointer vs by value in production C?

  Embedded note: every HAL handle you'll write in Project 2 is a struct accessed via pointer and the arrow operator. This is the template.
*/

struct Point {
  int x;
  int y;
};

struct Rect {
  struct Point first;
  struct Point second;
};

int compute_area(const struct Rect r);
void scale(struct Rect *r, const int h, const int b);

int main(void) {

  struct Point punt_a = {.x=2, .y=3};
  struct Point punt_b = {.x=4, .y=1};
  struct Point punt_c = {.x=4, .y=8};
  struct Point punt_d = {.x=3, .y=3};


  struct Rect rechthoek_a = {.first=punt_a, .second=punt_b};
  struct Rect rechthoek_b = {.first=punt_c, .second=punt_d};

  printf("Rechthoek a: oppervlakte van %d\nRechthoek b: oppervlakte van %d\n\n", compute_area(rechthoek_a),compute_area(rechthoek_b));

  printf("Rechthoek b had opp. %d\n", compute_area(rechthoek_b));
  scale(&rechthoek_b, 5, 5);
  printf("Nu heeft rechthoek b opp. %d", compute_area(rechthoek_b));
  return 0;
}

int compute_area(const struct Rect r) {

  int l = abs( r.first.x - r.second.x);
  int h = abs( r.first.y - r.second.y);

  int area = l * h;

  return area;
}

void scale(struct Rect *r, const int h, const int b) {
  r->second.x = r->first.x + h;
  r->second.y = r->first.y + b;
}

