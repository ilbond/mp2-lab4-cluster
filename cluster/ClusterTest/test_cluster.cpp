#include "gtest/gtest.h"
#include "pch.h"
#include "../cluster/Cluster.h"


TEST(Cluster, can_create_cluster) {
	ASSERT_NO_THROW(Cluster k);
}

TEST(Cluster, can_check_valid_task) {
	Cluster k;
	Task t;
	t.SetqProc(64);
	t.SetqCores(16);
	ASSERT_EQ(0, k.ValidTask(t));
}

TEST(Cluster, can_check_valid_task2) {
	Cluster k;
	Task t;
	t.SetqProc(1);
	t.SetqCores(1);
	ASSERT_EQ(1, k.ValidTask(t));
}

