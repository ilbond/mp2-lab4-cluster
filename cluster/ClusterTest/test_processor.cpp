#include "gtest/gtest.h"
#include "pch.h"
#include "../cluster/Cluster.h"

TEST(Processor, can_create_processor) {
	ASSERT_NO_THROW(Processor p);
}

TEST(Processor, can_check_empty) {
	Processor p;
	ASSERT_EQ(1, p.isEmpty());
}

TEST(Processor, can_check_empty2) {
	Processor p;
	Task t;
	t.SetqCores(2);
	p.AddTask(t);
	ASSERT_EQ(0, p.isEmpty());
}

TEST(Processor, can_check_add_task) {
	Processor p;
	p.SetallCores(5);
	Task t;
	t.SetqCores(2);
	ASSERT_EQ(1, p.CanAddTaskInProc(t));
}

TEST(Processor, can_add_task) {
	Processor p;
	p.SetallCores(5);
	Task t;
	t.SetqCores(2);
	p.AddTask(t);
	ASSERT_EQ(3, p.GetfreeCores());
}

TEST(Processor, can_finish_task) {
	Processor p;
	p.SetallCores(5);
	Task t;
	t.SetqCores(2);
	p.AddTask(t);
	p.FinishTask(t);
	ASSERT_EQ(5, p.GetfreeCores());
}

