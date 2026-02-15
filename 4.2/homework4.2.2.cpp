//подключаем макросы catch2
#include <catch2/catch_test_macros.hpp>
#include "catch2/catch_all.hpp"

#include <cstdint>

#include <iostream>

struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};

TEST_CASE("Test class List", "[List]") {
    SECTION("Test function PushBack") {
        INFO("Function PushBack is not working");
        List list_for_pushback;
        list_for_pushback.PushBack(100);
        list_for_pushback.PushBack(200);
        REQUIRE(list_for_pushback.PopBack() == 200);
    }
    SECTION("Test function PushFront") {
        INFO("Function PushFront is not working");
        List list_for_pushfront;
        list_for_pushfront.PushFront(100);
        list_for_pushfront.PushFront(200);
        REQUIRE(list_for_pushfront.PopFront() == 200);
    }
    SECTION("Test function PopBack") {
        INFO("Function PopBack is not working");
        List list_for_popback;
        CHECK_THROWS_AS(list_for_popback.PopBack(), std::runtime_error);
        CHECK_THROWS_WITH(list_for_popback.PopBack(), "list is empty");
        list_for_popback.PushBack(100);
        list_for_popback.PushBack(200);
        REQUIRE(list_for_popback.PopBack() == 200);
        REQUIRE(list_for_popback.Size() == 1);
    }
    SECTION("Test function PopFront") {
        INFO("Function PopFront is not working");
        List list_for_popfront;
        CHECK_THROWS_AS(list_for_popfront.PopFront(), std::runtime_error);
        CHECK_THROWS_WITH(list_for_popfront.PopFront(), "list is empty");
        list_for_popfront.PushFront(100);
        list_for_popfront.PushFront(200);
        REQUIRE(list_for_popfront.PopFront() == 200);
        REQUIRE(list_for_popfront.Size() == 1);
    }
    SECTION("Test multi function") {
        INFO("Multi function is not working");
        List list_for_multi;
        CHECK_THROWS_AS(list_for_multi.PopFront(), std::runtime_error);
        CHECK_THROWS_WITH(list_for_multi.PopFront(), "list is empty");
        list_for_multi.PushBack(100);
        list_for_multi.PushFront(200);
        REQUIRE(list_for_multi.Size() == 2);
        REQUIRE(list_for_multi.PopFront() == 200);
        REQUIRE(list_for_multi.Size() == 1);
        list_for_multi.PushBack(300);
        REQUIRE(list_for_multi.Size() == 2);
        REQUIRE(list_for_multi.PopBack() == 300);
    }
}