/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include "ui/widgets/side_bar_button.h"
#include "ui/widgets/scroll_area.h"
#include "ui/wrap/vertical_layout.h"

class ManageFiltersPrepare;

namespace Ui {
class VerticalLayoutReorder;
enum class FilterIcon : uchar;
} // namespace Ui

namespace Window {

class SessionController;

class FiltersMenu final {
public:
	FiltersMenu(
		not_null<Ui::RpWidget*> parent,
		not_null<SessionController*> session);
	~FiltersMenu();

private:
	void setup();
	void refresh();
	void setupList();
	void applyReorder(
		not_null<Ui::RpWidget*> widget,
		int oldPosition,
		int newPosition);
	[[nodiscard]] base::unique_qptr<Ui::SideBarButton> prepareButton(
		not_null<Ui::VerticalLayout*> container,
		FilterId id,
		const QString &title,
		Ui::FilterIcon icon);

	const not_null<SessionController*> _session;
	const not_null<Ui::RpWidget*> _parent;
	std::unique_ptr<ManageFiltersPrepare> _manage;
	Ui::RpWidget _outer;
	Ui::SideBarButton _menu;
	Ui::ScrollArea _scroll;
	not_null<Ui::VerticalLayout*> _container;
	Ui::VerticalLayout *_list = nullptr;
	std::unique_ptr<Ui::VerticalLayoutReorder> _reorder;
	base::unique_qptr<Ui::SideBarButton> _all;
	base::unique_qptr<Ui::SideBarButton> _setup;
	base::flat_map<FilterId, base::unique_qptr<Ui::SideBarButton>> _filters;
	FilterId _activeFilterId = 0;
	int _reordering = 0;

};

} // namespace Window