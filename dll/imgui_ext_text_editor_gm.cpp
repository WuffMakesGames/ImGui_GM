#include "imgui_gm.h"
#include "TextEditor.h"

std::vector<TextEditor> Editors;
#define GET_INDEX(_list, _index) YYGetReal(arg, _index); \
if (id < 0 || id >= _list.size()) {                      \
	Result.kind = VALUE_BOOL;                            \
	Result.val = 0;                                      \
	return;                                              \
}                                                        \

GMFUNC(__imgui_text_editor_create) {
	int id = Editors.size();
	TextEditor e;
	GMOVERRIDE(TextEditorCreate);

	Editors.push_back(e);
	Result.kind = VALUE_REAL;
	Result.val = id;
}

GMFUNC(__imgui_text_editor_set_tab_size) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	int enabled = YYGetReal(arg, 1);
	GMOVERRIDE(TextEditorSetTabSize);

	Editors[id].SetTabSize(enabled);
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_get_tab_size) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorGetTabSize);

	Result.kind = VALUE_REAL;
	Result.val = Editors[id].GetTabSize();
}

GMFUNC(__imgui_text_editor_set_insert_spaces_on_tabs) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	bool enabled = YYGetBool(arg, 1);
	GMOVERRIDE(TextEditorSetInsertSpacesOnTabs);

	Editors[id].SetInsertSpacesOnTabs(enabled);
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_is_insert_spaces_on_tabs) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorIsInsertSpacesOnTabs);

	Result.kind = VALUE_BOOL;
	Result.val = Editors[id].IsInsertSpacesOnTabs();
}

GMFUNC(__imgui_text_editor_set_line_spacing) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	float amount = YYGetFloat(arg, 1);
	GMOVERRIDE(TextEditorSetLineSpacing);

	Editors[id].SetLineSpacing(amount);
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_get_line_spacing) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorGetLineSpacing);

	Result.kind = VALUE_REAL;
	Result.val = Editors[id].GetLineSpacing();
}

GMFUNC(__imgui_text_editor_set_read_only_enabled) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	bool enabled = YYGetBool(arg, 1);
	GMOVERRIDE(TextEditorSetReadOnlyEnabled);

	Editors[id].SetReadOnlyEnabled(enabled);
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_is_read_only_enabled) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorIsReadOnlyEnabled);

	Result.kind = VALUE_BOOL;
	Result.val = Editors[id].IsReadOnlyEnabled();
}

GMFUNC(__imgui_text_editor_set_auto_indent_enabled) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	bool enabled = YYGetBool(arg, 1);
	GMOVERRIDE(TextEditorSetAutoIndentEnabled);

	Editors[id].SetAutoIndentEnabled(enabled);
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_is_auto_indent_enabled) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorIsAutoIndentEnabled);

	Result.kind = VALUE_BOOL;
	Result.val = Editors[id].IsAutoIndentEnabled();
}

GMFUNC(__imgui_text_editor_set_show_whitespaces_enabled) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	bool enabled = YYGetBool(arg, 1);
	GMOVERRIDE(TextEditorSetShowWhitespacesEnabled);

	Editors[id].SetShowWhitespacesEnabled(enabled);
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_is_show_whitespaces_enabled) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorIsShowWhitespacesEnabled);

	Result.kind = VALUE_BOOL;
	Result.val = Editors[id].IsShowWhitespacesEnabled();
}

GMFUNC(__imgui_text_editor_set_show_spaces_enabled) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	bool enabled = YYGetBool(arg, 1);
	GMOVERRIDE(TextEditorSetShowSpacesEnabled);

	Editors[id].SetShowSpacesEnabled(enabled);
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_is_show_spaces_enabled) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorIsShowSpacesEnabled);

	Result.kind = VALUE_BOOL;
	Result.val = Editors[id].IsShowSpacesEnabled();
}

GMFUNC(__imgui_text_editor_set_show_tabs_enabled) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	bool enabled = YYGetBool(arg, 1);
	GMOVERRIDE(TextEditorSetShowTabsEnabled);

	Editors[id].SetShowTabsEnabled(enabled);
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_is_show_tabs_enabled) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorIsShowTabsEnabled);

	Result.kind = VALUE_BOOL;
	Result.val = Editors[id].IsShowTabsEnabled();
}

GMFUNC(__imgui_text_editor_set_show_line_numbers_enabled) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	bool enabled = YYGetBool(arg, 1);
	GMOVERRIDE(TextEditorSetShowLineNumbersEnabled);

	Editors[id].SetShowLineNumbersEnabled(enabled);
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_is_show_line_numbers_enabled) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorIsShowLineNumbersEnabled);

	Result.kind = VALUE_BOOL;
	Result.val = Editors[id].IsShowLineNumbersEnabled();
}

GMFUNC(__imgui_text_editor_set_show_scrollbar_mini_map_enabled) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	bool enabled = YYGetBool(arg, 1);
	GMOVERRIDE(TextEditorSetShowScrollbarMiniMapEnabled);

	Editors[id].SetShowScrollbarMiniMapEnabled(enabled);
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_is_show_scrollbar_mini_map_enabled) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorIsShowScrollbarMiniMapEnabled);

	Result.kind = VALUE_BOOL;
	Result.val = Editors[id].IsShowScrollbarMiniMapEnabled();
}

GMFUNC(__imgui_text_editor_set_show_pan_scroll_indicator_enabled) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	bool enabled = YYGetBool(arg, 1);
	GMOVERRIDE(TextEditorSetShowPanScrollIndicatorEnabled);

	Editors[id].SetShowPanScrollIndicatorEnabled(enabled);
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_is_show_pan_scroll_indicator_enabled) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorIsShowPanScrollIndicatorEnabled);

	Result.kind = VALUE_BOOL;
	Result.val = Editors[id].IsShowPanScrollIndicatorEnabled();
}

GMFUNC(__imgui_text_editor_set_show_matching_brackets) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	bool enabled = YYGetBool(arg, 1);
	GMOVERRIDE(TextEditorSetShowMatchingBrackets);

	Editors[id].SetShowMatchingBrackets(enabled);
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_is_showing_matching_brackets) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorIsShowingMatchingBrackets);

	Result.kind = VALUE_BOOL;
	Result.val = Editors[id].IsShowingMatchingBrackets();
}

GMFUNC(__imgui_text_editor_set_complete_paired_glyphs) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	bool enabled = YYGetBool(arg, 1);
	GMOVERRIDE(TextEditorSetCompletePairedGlyphs);

	Editors[id].SetCompletePairedGlyphs(enabled);
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_is_completing_paired_glyphs) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorIsCompletingPairedGlyphs);

	Result.kind = VALUE_BOOL;
	Result.val = Editors[id].IsCompletingPairedGlyphs();
}

GMFUNC(__imgui_text_editor_set_overwrite_enabled) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	bool enabled = YYGetBool(arg, 1);
	GMOVERRIDE(TextEditorSetOverwriteEnabled);

	Editors[id].SetOverwriteEnabled(enabled);
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_is_overwrite_enabled) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorIsOverwriteEnabled);

	Result.kind = VALUE_BOOL;
	Result.val = Editors[id].IsOverwriteEnabled();
}

GMFUNC(__imgui_text_editor_set_middle_mouse_pan_mode) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorSetMiddleMousePanMode);

	Editors[id].SetMiddleMousePanMode();
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_set_middle_mouse_scroll_mode) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorSetMiddleMouseScrollMode);

	Editors[id].SetMiddleMouseScrollMode();
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_is_middle_mouse_pan_mode) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorIsMiddleMousePanMode);

	Result.kind = VALUE_BOOL;
	Result.val = Editors[id].IsMiddleMousePanMode();
}

GMFUNC(__imgui_text_editor_set_text) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	const char* text = YYGetString(arg, 1);
	GMOVERRIDE(TextEditorSetText);

	Editors[id].SetText(text);
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_get_text) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorGetText);
	GMRETURNS(String);

	YYCreateString(&g_Copy, Editors[id].GetText().c_str());
	COPY_RValue(&Result, &g_Copy);
}

GMFUNC(__imgui_text_editor_get_cursor_text) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	double cursor = YYGetReal(arg, 1);
	GMOVERRIDE(TextEditorGetCursorText);
	GMRETURNS(String);

	YYCreateString(&g_Copy, Editors[id].GetCursorText(cursor).c_str());
	COPY_RValue(&Result, &g_Copy);
}

GMFUNC(__imgui_text_editor_get_line_text) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	int line = YYGetReal(arg, 1);
	GMOVERRIDE(TextEditorGetLineText);
	GMRETURNS(String);

	YYCreateString(&g_Copy, Editors[id].GetLineText(line).c_str());
	COPY_RValue(&Result, &g_Copy);
}

GMFUNC(__imgui_text_editor_get_section_text) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	int start_line = YYGetReal(arg, 1);
	int start_column = YYGetReal(arg, 2);
	int end_line = YYGetReal(arg, 3);
	int end_column = YYGetReal(arg, 4);
	GMOVERRIDE(TextEditorGetSectionText);
	GMRETURNS(String);

	YYCreateString(&g_Copy, Editors[id].GetSectionText(start_line, start_column, end_line, end_column).c_str());
	COPY_RValue(&Result, &g_Copy);
}

GMFUNC(__imgui_text_editor_replace_section_text) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	int start_line = YYGetReal(arg, 1);
	int start_column = YYGetReal(arg, 2);
	int end_line = YYGetReal(arg, 3);
	int end_column = YYGetReal(arg, 4);
	const char* text = YYGetString(arg, 5);
	GMOVERRIDE(TextEditorReplaceSectionText);
	GMRETURNS(String);

	Editors[id].ReplaceSectionText(start_line, start_column, end_line, end_column, text);
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_clear_text) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorClearText);

	Editors[id].SetText("");
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_is_empty) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorIsEmpty);

	Result.kind = VALUE_BOOL;
	Result.val = Editors[id].IsEmpty();
}

GMFUNC(__imgui_text_editor_get_line_count) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorGetLineCount);

	Result.kind = VALUE_REAL;
	Result.val = Editors[id].GetLineCount();
}

GMFUNC(__imgui_text_editor_render) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	const char* title = YYGetString(arg, 1);
	double width = YYGetReal(arg, 2);
	GMDEFAULT(0);
	double height = YYGetReal(arg, 3);
	GMDEFAULT(0);
	bool border = YYGetBool(arg, 4);
	GMDEFAULT(false);
	GMOVERRIDE(TextEditorRender);

	Editors[id].Render(title, ImVec2(width, height), border);
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_set_focus) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorSetFocus);

	Editors[id].SetFocus();
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_cut) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorCut);

	Editors[id].Cut();
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_copy) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorCopy);

	Editors[id].Copy();
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_paste) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorPaste);

	Editors[id].Paste();
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_undo) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorUndo);

	Editors[id].Undo();
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_redo) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorRedo);

	Editors[id].Redo();
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_can_undo) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorCanUndo);

	Result.kind = VALUE_BOOL;
	Result.val = Editors[id].CanUndo();
}

GMFUNC(__imgui_text_editor_can_redo) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorCanRedo);

	Result.kind = VALUE_BOOL;
	Result.val = Editors[id].CanRedo();
}

GMFUNC(__imgui_text_editor_get_undo_index) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorGetUndoIndex);

	Result.kind = VALUE_REAL;
	Result.val = Editors[id].GetUndoIndex();
}

GMFUNC(__imgui_text_editor_set_cursor) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	int line = YYGetReal(arg, 1);
	int column = YYGetReal(arg, 2);
	GMOVERRIDE(TextEditorSetCursor);

	Editors[id].SetCursor(line, column);
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_select_all) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorSelectAll);

	Editors[id].SelectAll();
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_select_line) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	int line = YYGetReal(arg, 1);
	GMOVERRIDE(TextEditorSelectLine);

	Editors[id].SelectLine(line);
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_select_lines) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	int start = YYGetReal(arg, 1);
	int end = YYGetReal(arg, 2);
	GMOVERRIDE(TextEditorSelectLines);

	Editors[id].SelectLines(start, end);
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_select_region) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	int start_line = YYGetReal(arg, 1);
	int start_column = YYGetReal(arg, 2);
	int end_line = YYGetReal(arg, 3);
	int end_column = YYGetReal(arg, 4);
	GMOVERRIDE(TextEditorSelectRegion);

	Editors[id].SelectRegion(start_line, start_column, end_line, end_column);
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_select_to_brackets) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	bool include_brackets = YYGetBool(arg, 1);
	GMDEFAULT(true);
	GMOVERRIDE(TextEditorSelectToBrackets);

	Editors[id].SelectToBrackets(include_brackets);
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_grow_selections_to_curly_brackets) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorGrowSelectionsToCurlyBrackets);

	Editors[id].GrowSelectionsToCurlyBrackets();
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_shrink_selections_to_curly_brackets) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorShrinkSelectionsToCurlyBrackets);

	Editors[id].ShrinkSelectionsToCurlyBrackets();
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_add_next_occurrence) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorAddNextOccurrence);

	Editors[id].AddNextOccurrence();
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_select_all_occurrences) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorSelectAllOccurrences);

	Editors[id].SelectAllOccurrences();
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_any_cursor_has_selection) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorAnyCursorHasSelection);

	Result.kind = VALUE_BOOL;
	Result.val = Editors[id].AnyCursorHasSelection();
}

GMFUNC(__imgui_text_editor_all_cursors_have_selection) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorAllCursorsHaveSelection);

	Result.kind = VALUE_BOOL;
	Result.val = Editors[id].AllCursorsHaveSelection();
}

GMFUNC(__imgui_text_editor_current_cursor_has_selection) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorCurrentCursorHasSelection);

	Result.kind = VALUE_BOOL;
	Result.val = Editors[id].CurrentCursorHasSelection();
}

GMFUNC(__imgui_text_editor_clear_cursors) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorClearCursors);

	Editors[id].ClearCursors();
	Result.kind = VALUE_BOOL;
	Result.val = true;
}

GMFUNC(__imgui_text_editor_get_first_visible_line) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorGetFirstVisibleLine);

	Result.kind = VALUE_REAL;
	Result.val = Editors[id].GetFirstVisibleLine();
}

GMFUNC(__imgui_text_editor_get_last_visible_line) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorGetLastVisibleLine);

	Result.kind = VALUE_REAL;
	Result.val = Editors[id].GetLastVisibleLine();
}

GMFUNC(__imgui_text_editor_get_first_visible_column) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorGetFirstVisibleColumn);

	Result.kind = VALUE_REAL;
	Result.val = Editors[id].GetFirstVisibleColumn();
}

GMFUNC(__imgui_text_editor_get_last_visible_column) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorGetLastVisibleColumn);

	Result.kind = VALUE_REAL;
	Result.val = Editors[id].GetLastVisibleColumn();
}

GMFUNC(__imgui_text_editor_get_line_height) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorGetLineHeight);

	Result.kind = VALUE_REAL;
	Result.val = Editors[id].GetLineHeight();
}

GMFUNC(__imgui_text_editor_get_glyph_width) {
	int id = GET_INDEX(Editors, 0);
	GMHINT(Real);
	GMOVERRIDE(TextEditorGetGlyphWidth);

	Result.kind = VALUE_REAL;
	Result.val = Editors[id].GetGlyphWidth();
}