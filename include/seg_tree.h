#ifndef TOOLS_SEG_TREE_H
#define TOOLS_SEG_TREE_H

#include <vector>

typedef long (*MergeFunc)(long, long);

class SegmentTree {
public:
  SegmentTree(const long size) : m_func(nullptr) { t.resize(size); }
  void set_merge_func(MergeFunc m_f) { m_func = m_f; }
  void init(long arr[], long size) { build(arr, 1, 1, size); };
  long query(long l, long r) { return query(1, l, r); }
  void update(long l, long r, long v) { return update(1, l, r, v); }

private:
  void build(long arr[], long k, long l, long r) {
    t[k].l = l;
    t[k].r = r;
    if (l == r) {
      t[k].v = arr[l - 1];
      t[k].lz = -1;
      return;
    }
    long mid = (l + r) / 2, lc = 2 * k, rc = 2 * k + 1;
    build(arr, lc, l, mid);
    build(arr, rc, mid + 1, r);
    t[k].v = m_func(t[lc].v, t[rc].v);
    t[k].lz = -1;
  }

  long query(long k, long l, long r) {
    if (t[k].l >= l && t[k].r <= r) {
      return t[k].v;
    }
    if (t[k].lz != -1) {
      push_down(k);
    }
    long mid = (t[k].l + t[k].r) / 2, lc = k * 2, rc = k * 2 + 1;
    long value = 0, flag = 0;
    if (l <= mid) {
      value = query(lc, l, r);
      flag = 1;
    }
    if (r > mid) {
      long v = query(rc, l, r);
      value = flag ? m_func(value, v) : v;
    }
    return value;
  }

  void update(long k, long l, long r, long v) {
    if (t[k].l >= l && t[k].r <= r) {
      lazy(k, v);
      return;
    }
    if (t[k].lz != -1) {
      push_down(k);
    }
    long mid = (t[k].l + t[k].r) / 2, lc = k * 2, rc = k * 2 + 1;
    if (l <= mid)
      update(lc, l, r, v);
    if (r > mid)
      update(rc, l, r, v);
    t[k].v = m_func(t[lc].v, t[rc].v);
  }

  void push_down(long k) {
    lazy(k * 2, t[k].lz);
    lazy(k * 2 + 1, t[k].lz);
    t[k].lz = -1;
  }

  void lazy(long k, long v) { t[k].v = v, t[k].lz = v; }

private:
  struct Node {
    long l, r, lz, v;
  };
  std::vector<Node> t;
  MergeFunc m_func;
};

#endif // TOOLS_SEG_TREE_H
