#include "Menu.h"

namespace Ark
{
	// ############################## MenuItem ##############################

	bool MenuItem::match(const char* input) const
	{
		return strcmp(m_InputValue, input) == 0;
	}

	// ############################## Menu ##############################

	const char** Menu::GetItemLabels(size_t& outSize)
	{
		outSize = items.size();
		const char** labels = new const char* [outSize];
		for (size_t i = 0; i < outSize; i++)
		{
			labels[i] = items.at(i).m_Label;
		}
		return labels;
	}

	void Menu::AddItem(const char* label, const char* inputValues, Menu* target)
	{
		items.push_back(MenuItem(label, inputValues, target));
	}

	Menu* Menu::CheckInput(const char* input)
	{
		for (size_t i = 0; i < items.size(); i++)
		{
			MenuItem* item = &items.at(i);
			if (item->match(input))
				return item->m_Target;
				
		}
		return nullptr;
	}
}