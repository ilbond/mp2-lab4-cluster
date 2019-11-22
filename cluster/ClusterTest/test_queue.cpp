#include "pch.h"
#include "../cluster/Cluster.h"

TEST(queue, can_create_queue) {
	ASSERT_NO_THROW(queue<Task> q);

}

TEST(queue, can_check_empty) {
	queue<Task> q;
	ASSERT_EQ(1,q.isEmpty());
}

TEST(queue, can_check_empty2) {
	queue<int> q;
	q.push(1);
	ASSERT_EQ(0, q.isEmpty());
}

TEST(queue, can_get_first) {
	queue<int> q;
	q.push(1);
	ASSERT_EQ(1, q.GetFirst());
}
TEST(queue, can_push) {
	queue<int> q;
	q.push(1);
	ASSERT_EQ(q.GetFirst(),1);
}

TEST(queue, cant_pop_in_empty) {
	queue<int> q;
	ASSERT_ANY_THROW(q.pop());
}

TEST(queue, can_pop) {
	queue<int> q;
	q.push(1);
	q.pop();
	ASSERT_EQ(1,q.isEmpty());
}

TEST(queue, can_pop_element) {
	queue<int> q;
	q.push(1);
	ASSERT_EQ(1, q.pop());
}

TEST(queue, pop_first)
{
	queue<int> q;
	q.push(1);
	q.push(2);
	EXPECT_EQ(q.pop(), 1);
}

TEST(queue, cant_get_first_in_empty) {
	queue<int> q;
	ASSERT_ANY_THROW(q.GetFirst());
}

TEST(queue, can_get_size)
{
	queue<int> q;
	q.push(1);
	q.push(2);
	EXPECT_EQ(q.GetSize(), 2);
}