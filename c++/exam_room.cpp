#include <iostream>
#include <set>

using namespace std;

class ExamRoom
{
public:
  ExamRoom(int N)
  {
    max_seat_ = N;
  }

  int seat()
  {
    if (seats_.empty())
    {
      seats_.insert(0);
      return 0;
    }
    if (seats_.size() == max_seat_)
    {
      return -1;
    }

    int current_seat = 0;
    int max_distance = 0;
    for (auto left = seats_.begin(); left != --seats_.end(); left++)
    {
      auto right = left;
      right++;
      int distance = (*right - *left) / 2;
      if (distance > max_distance)
      {
        max_distance = distance;
        current_seat = (*right + *left) / 2;
      }
    }
    int first_seat = *seats_.begin();
    if (first_seat != 0 && first_seat >= max_distance)
    {
      max_distance = first_seat;
      current_seat = 0;
    }
    int last_seat = *(--seats_.end());
    if (last_seat != max_seat_ - 1 && max_seat_ - last_seat - 1 > max_distance)
    {
      max_distance = max_seat_ - last_seat - 1;
      current_seat = max_seat_ - 1;
    }
    seats_.insert(current_seat);

    return current_seat;
  }

  void leave(int p)
  {
    seats_.erase(p);
  }

private:
  int max_seat_ = 0;
  set<int> seats_;
};

int main()
{
  ExamRoom* obj = new ExamRoom(10);

  int p1 = obj->seat();
  cout << p1 << endl;

  int p2 = obj->seat();
  cout << p2 << endl;
  
  int p3 = obj->seat();
  cout << p3 << endl;

  int p4 = obj->seat();
  cout << p4 << endl;

  obj->leave(4);

  int p5 = obj->seat();
  cout << p5 << endl;

  return 0;
}
