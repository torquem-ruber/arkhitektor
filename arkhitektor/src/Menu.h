#pragma once
#include <string>
#include <array>

namespace Ark
{
	/*
	class MenuItem
	{
	public:
		MenuItem(const string label, const string inputValue, void* link)
			: m_Label(label), m_InputValue(inputValue), m_Link(link) {}

		bool match(const string input) const
		{
			return input == m_InputValue;
		}

	private:
		const string m_Label;
		const string m_InputValue;
		void* m_Link;
	};
	*/

	class Menu
	{
	public:
		Menu(std::string* title) 
			: m_Title(title) {}

		void AddItem(std::string* label)
		{
		}
	private:
		std::string* m_Title;
		std::array<std::string, 1>* m_Items = new std::array<std::string, 1>();
	};
}