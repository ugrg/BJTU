#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct Item {
  int index;
  int value;
  Item *child;
  Item *sibling;
};

struct V {
  int l;
  int r;
};

bool comp(V &a,V &b){
  return a.l > b.l;
}

list<V> deep(Item &node) {
  list<V> values;
  Item *chd = node.child;
  while(chd) {
    values.splice(values.end(),deep(*chd));
  }
  V v={node.value,node.value};
  values.push_front(v);
  values.sort(comp);
  list<V> result;
  V L = values.front();
  for(list<V>::iterator p = ++values.begin(); p!=values.end(); p++){
    V R = *p;
  }
  return values;
}


class Solution {
  public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
      Item node= {-1,0,NULL,NULL};
      vector<Item> tree(nums.size(),node);
      for(int i=0; i < tree.size(); i++) {
        tree[i].value = nums[i];
        int index = parents[i];
        if(index == -1) continue;
        tree[i].sibling = tree[index].child;
        tree[index].child = &tree[i];
      }

      return vector<int>(parents.size(),1);
    }
};