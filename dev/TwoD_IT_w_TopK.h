#ifndef E_TWOD_IT_W_TOPK
#define E_TWOD_IT_W_TOPK


#include "trees/interval_tree.h"
#include "trees/TemplateStack.H"
#include <string>
#include <vector>


class TwoD_Interval: public Interval {
public:
  TwoD_Interval(const std::string id, const int low, const int high, const int max_timestamp)
    : _id(id), _low(low), _high(high), _max_timestamp(max_timestamp) {};
  
  std::string GetId() const {return _id};
  int GetLowPoint() const {return _low};
  int GetHighPoint() const {return _high};
  int GetMaxTimeStamp() const {return _max_timestamp};

protected:
  std::string _id;
  int _low;
  int _high;
  int _max_timestamp;
};

class TwoD_IT_w_TopK {
public:
  IntervalTree();
  IntervalTree(const std::string & filename);
  void insertInterval(std::string id, int minKey, int maxKey, int maxTimestamp);
  void deleteInterval(std::string id);
  std::vector<TwoD_Interval> topK(int Key, int k);
  void sync(const std::string & filename);

private:
  IntervalTree storage;
};


#endif
