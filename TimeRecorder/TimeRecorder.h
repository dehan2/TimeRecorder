#pragma once

#include "stdafx.h"
#include <string>
#include <functional>
#include <chrono>

#include <iostream>

using namespace std;

template <typename R, typename... Args> //R: ReturnType, Args: arguments
class TimeRecorder
{
private:
	string m_tag;
	float m_record;
	function<R(Args ...)> m_functionToRecord;

public:
	TimeRecorder(const string& tag, function<R(Args ...)> functionToRecord);
	~TimeRecorder();

	const string& get_tag() const { return m_tag; }
	const float& get_record() const { return m_record; }

	void set_tag(const string& tag) { m_tag = tag; }

	R operator()(Args ... args);
};

template <typename R, typename... Args>
TimeRecorder<R, Args ...>::TimeRecorder(const string& tag, function<R(Args ...)> functionToRecord)
{
	m_tag = tag;
	m_functionToRecord = functionToRecord;
}

template <typename R, typename... Args>
TimeRecorder<R, Args ...>::~TimeRecorder()
{
}

template <typename R, typename... Args>
R TimeRecorder<R, Args ...>::operator()(Args ... args)
{
	auto start = chrono::system_clock::now();
	
	R returnValue = m_functionToRecord(args...);

	auto end = chrono::system_clock::now();
	auto diff = end - start;
	m_record = chrono::duration<float, milli>(diff).count();
	
	return returnValue;
}
