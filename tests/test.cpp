#include "pch.h"
#include "..\lab8Calculator\Calculator.cpp"
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
//for class Stack
TEST(StackTest, PushPopTest) {
	Stack<int> stack;
	stack << 1 << 2 << 3;
	int value;
	stack >> value;
	EXPECT_EQ(value, 3);
	stack >> value;
	EXPECT_EQ(value, 2);
	stack >> value;
	EXPECT_EQ(value, 1);
}

TEST(StackTest, EqualTest) {
	Stack<int> stack1;
	Stack<int> stack2;
	stack1<< 1 << 2 << 3;
	stack2<< 1 << 2 << 3;
	EXPECT_TRUE(stack1 == stack2);
	stack1 << 4;
	EXPECT_FALSE(stack1 == stack2);
}

TEST(StackTest, LessTest) {
	Stack<int> stack1;
	Stack<int> stack2;
	stack1 << 1 << 2 << 3;
	stack2 << 1 << 2;
	EXPECT_TRUE(stack2 < stack1);
}

TEST(StackTest, IndexTest) {
	Stack<int> stack;
	stack << 1 << 2 << 3;
	EXPECT_EQ(stack[0], 1);
	EXPECT_EQ(stack[1], 2);
	EXPECT_EQ(stack[2], 3);
}
TEST(STackTest, ISEmptyTest) {
	Stack<int> stack;
	stack << 1 << 2 << 3;
	EXPECT_FALSE(stack.isEmpty());
}

//for class Calculator 

TEST(CalculatorTest, ProcessExprTest) {
	Calculator calc;
	EXPECT_TRUE(calc.processExpr("(2-1)/(1+0)"));
	EXPECT_FALSE(calc.processExpr("(2-1/1+"));
	EXPECT_FALSE(calc.processExpr("-1637/)"));
}

TEST(CalculatorTest, CalculateExprTest) {
	Calculator calc;
	EXPECT_EQ(calc.calculateExpr("(10-2)/(3+1)"),2.0);
	EXPECT_EQ(calc.calculateExpr("(5+4)/(3+0)"), 3.0);
	EXPECT_THROW(calc.calculateExpr("(5+4)/(3+0"), std::exception);
}
TEST(CalculatorTest, IsOperatorTest){
	Calculator calc;
	EXPECT_FALSE(calc.isOperator('k'));
	EXPECT_FALSE(calc.isOperator('%'));
	EXPECT_FALSE(calc.isOperator('7'));

	EXPECT_TRUE(calc.isOperator('-'));
	EXPECT_TRUE(calc.isOperator('+'));
	EXPECT_TRUE(calc.isOperator('/'));
	EXPECT_TRUE(calc.isOperator('*'));
}
TEST(CalculatorTest, IsCorrectExprTest){
	Calculator calc;
	EXPECT_TRUE(calc.isCorrectExpr("(2+3)"));
	EXPECT_TRUE(calc.isCorrectExpr("((2+3)*3)"));
	EXPECT_TRUE(calc.isCorrectExpr("((2+3)*(4-2))/(1+1)"));
	EXPECT_FALSE(calc.isCorrectExpr("(2-"));
	EXPECT_FALSE(calc.isCorrectExpr("(2-473"));
	EXPECT_FALSE(calc.isCorrectExpr("(2-1)*3)"));
}
TEST(CalculatorTest, InfixToPostfixExprTest){
	Calculator calc;
	EXPECT_EQ(calc.infixToPostfix("(2+6)"), "2 6 +");
	EXPECT_EQ(calc.infixToPostfix("(7-3)"), "7 3 -");
	EXPECT_EQ(calc.infixToPostfix("(2+1)*(4-3)"), "2 1 + 4 3 - *");
	EXPECT_EQ(calc.infixToPostfix("(2+6)*(4-2)/(1+1)"), "2 6 + 4 2 - * 1 1 + /");
}
TEST(CalculatorTest, CalculatePostfixTest){
	Calculator calc;
	EXPECT_DOUBLE_EQ(calc.calculatePostfix("2 6 +"), 8.0);
	EXPECT_DOUBLE_EQ(calc.calculatePostfix("7 3.5 -"), 3.5);
	EXPECT_DOUBLE_EQ(calc.calculatePostfix("2 1 + 4 3 - *"), 3.0);
	EXPECT_DOUBLE_EQ(calc.calculatePostfix("2 6 + 4 2 - * 1 1 + /"), 8.0);
}