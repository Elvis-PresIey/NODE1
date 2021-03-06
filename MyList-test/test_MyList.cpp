#include "MyList.h"
#include "MyList.cpp"
#include <gtest.h>

TEST(testList, CreateEmptyList) {
  CNode *head = CreateList(0, 0);
  CNode *expected_head = 0;
  EXPECT_EQ(expected_head, head);
}

TEST(testList, CreateList) {
  const int kListSize = 10;
  int vals[kListSize];
  for (int i = 0; i < kListSize; ++i)
    vals[i] = i + 1;
  CNode *head = CreateList(kListSize, vals);

  int k = 0;
  while (head != 0) {
    EXPECT_EQ(vals[k], head->val);
    head = head->next;
    ++k;
  }
  EXPECT_EQ(kListSize, k);
}

TEST(testList, mergetest) {
	const int kListSize1 = 5;
	int vals1[kListSize1];
	for (int i = 0; i < kListSize1; i++)
		vals1[i] = i + 5;
	CNode *Head = CreateList(kListSize1, vals1);
	const int kListSize2 =10;
	int vals2[kListSize2];
	for (int i = 0; i < kListSize2; i++)
		vals2[i] = i + 5;
	CNode *Head1 = CreateList(kListSize2, vals2);
	int j = 2;
	ASSERT_NO_THROW(merge(&Head,Head1,j,kListSize2));
}

TEST(testList, mergetest_wrong_index) {
	const int kListSize1 = 5;
	int vals1[kListSize1];
	for (int i = 0; i < kListSize1; i++)
		vals1[i] = i + 5;
	CNode *Head = CreateList(kListSize1, vals1);
	const int kListSize2 =10;
	int vals2[kListSize2];
	for (int i = 0; i < kListSize2; i++)
		vals2[i] = i + 5;
	CNode *Head1 = CreateList(kListSize2, vals2);
	int j = 20;
	ASSERT_ANY_THROW(merge(&Head,Head1,j,kListSize2));
}

TEST(testList, can_merge) {
	const int kListSize1 = 5;
	int vals1[kListSize1];
	for (int i = 0; i < kListSize1; i++)
		vals1[i] = i + 1;
	CNode *Head = CreateList(kListSize1, vals1);
	const int kListSize2 = 10;
	int vals2[kListSize2];
	for (int i = 0; i < kListSize2; i++)
		vals2[i] = i + 10;
	CNode *Head1 = CreateList(kListSize2, vals2);
	int j = 2;

	const int kListSize3 = kListSize1 + kListSize2;
	int vals3[kListSize3];
	for (int i = 0; i < 3; i++)
		vals3[i] = i + 1;
	for (int i = 3; i < 3 + kListSize2; i++)
		vals3[i] = i + 10 - 3;
	for (int i = 3 + kListSize2; i < kListSize3; i++)
		vals3[i] = i + 1 - kListSize2;
	CNode *Head3 = CreateList(kListSize3, vals3);
	print(Head3);
	std::cout<<std::endl;
	merge(&Head, Head1, j, kListSize1);
	print(Head);
	EXPECT_EQ(true, myCompare(Head, Head3));
}

TEST(testList, can_merge_with_emptyList) {
	const int kListSize1 = 5;
	int vals1[kListSize1];
	for (int i = 0; i < kListSize1; i++)
		vals1[i] = i + 1;
	CNode *Head = CreateList(kListSize1, vals1);
	int j = 2;
	CNode* Head1 = NULL;
	ASSERT_ANY_THROW(merge(&Head,Head1,j,kListSize1));
}

TEST(testList, can_merge_empty_list) {
	
	CNode *Head = NULL;
	const int kListSize2 = 10;
	int vals2[kListSize2];
	for (int i = 0; i < kListSize2; i++)
		vals2[i] = i + 10;
	CNode *Head1 = CreateList(kListSize2, vals2);
	int j = 2;

	const int kListSize3 = kListSize2;
	int vals3[kListSize3];
	for (int i = 0; i < kListSize2; i++)
		vals3[i] = i + 10;
	CNode *Head3 = CreateList(kListSize3, vals3);
	print(Head3);
	std::cout<<std::endl;
	merge(&Head, Head1, j, kListSize2);
	print(Head);
	EXPECT_EQ(true, myCompare(Head, Head3));
}
