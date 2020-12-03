#pragma once
#include <vector>

namespace Ark
{
	class Menu;
	class MenuItem
	{
	public:
		Menu* m_Target;
		const char* m_Label;
	public:
		MenuItem(const char* label, const char* inputValue, Menu* target = nullptr)
			: m_Label(label), m_InputValue(inputValue), m_Target(target) {}

		bool match(const char* input) const;

	private:
		const char* m_InputValue;
	};

	class Menu
	{
	public:
		void(*m_Event)();
		const char* m_Title;
		bool m_Animate;
	public:
		Menu(const char* title, bool animate = true) : m_Title(title), m_Event(nullptr), m_Animate(animate) {}
		Menu(void(*event)()) : m_Title(nullptr), m_Event(event) {}

		const char** GetItemLabels(size_t& outSize);
		void AddItem(const char* label, const char* inputValues, Menu* target = nullptr);
		Menu* CheckInput(const char* input);

	private:
		std::vector<MenuItem> items;
	};
}