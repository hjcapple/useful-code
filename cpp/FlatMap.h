#ifndef __CLOVER_FLATMAP_H__
#define __CLOVER_FLATMAP_H__

namespace clover {

    template <typename Key, typename T, size_t MaxSize>
    class FlatMap final {
    public:
        static constexpr size_t kMaxSize = MaxSize;

        typedef std::pair<Key, T> value_type;
        typedef std::pair<Key, T> Item;
        typedef const Item* const_iterator;

        FlatMap() {
            m_size = 0;
        }

        template <size_t N>
        void init(const Item (&items)[N]) {
            static_assert(N <= MaxSize, "");

            m_size = N;
            std::copy(items, items + N, m_items);
            std::sort(m_items, m_items + m_size, [](const Item &lhs, const Item &rhs) {
                return lhs.first < rhs.first;
            });
        }

        const Item *begin() const {
            return m_items;
        }

        const Item *end() const {
            return m_items + m_size;
        }

        size_t size() const {
            return m_size;
        }

        const Item *find(Key key) const {
            const auto endIter = m_items + m_size;
            auto iter = std::lower_bound(m_items, endIter, key, [](const Item &item, Key key) {
                return item.first < key;
            });
            if (iter != endIter && iter->first == key) {
                return iter;
            }
            return endIter;
        }

    private:
        // 使用二分查找数组来替代 std::map, 减少内存占用
        Item m_items[MaxSize];
        size_t m_size;
    };
}


#endif
