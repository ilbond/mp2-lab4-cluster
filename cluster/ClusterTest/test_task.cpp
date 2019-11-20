#include "gtest/gtest.h"
#include "pch.h"
#include "../cluster/Cluster.h"

TEST(Task, can_create_task) {
	ASSERT_NO_THROW(Task t);

}

TEST(Task, can_check_done) {
	Task t;
	ASSERT_EQ(0, t.isDone());
}

TEST(Task, can_check_done2) {
	Task t;
	int a = t.getTacts();
	for (int i = 0; i < a; i++) {
		t.TaskTact();
	}
	ASSERT_EQ(1, t.isDone());
}

TEST(Task, can_get_id) {
	Task t;
	ASSERT_EQ("", t.getID());
}