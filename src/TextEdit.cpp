#include "GuiElements/TextEdit.h"
#include <cmath>
#include <map>

TextEdit::TextEdit(const char* id, RayRect body, IGuiElement* parent)
: IGuiElement(id, body, parent) {
    this->line_ = 0;
    this->cursor_ = 0;
    this->start_index_ = 0;
    this->start_line_ = 0;
    this->text_ = {""};
    this->is_in_focus_ = false;
}

bool TextEdit::is_in_focus() {
    return is_in_focus_;
}

std::vector<std::string> TextEdit::text() {
    return text_;
}

std::string TextEdit::line(size_t line) {
    if (line > text_.size()) return "";
    return text_[line];
}

void TextEdit::update(double deltaTime) {
    this->update_size();
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {

        Vector2 mouse = GetMousePosition();
        if ((realbody_.x < mouse.x) && (mouse.x < (realbody_.x + realbody_.width)) &&
            (realbody_.y < mouse.y) && (mouse.y < (realbody_.y + realbody_.height))
        )     
        {
            this->is_in_focus_ = true;
        } else {
            this->is_in_focus_ = false;
        }
    }
    std::map<bool, std::map<int, char>> charmap = {
        {false, 
            {{KEY_A, 'a'},
            {KEY_B, 'b'},
            {KEY_C, 'c'},
            {KEY_D, 'd'},
            {KEY_E, 'e'},
            {KEY_F, 'f'},
            {KEY_G, 'g'},
            {KEY_H, 'h'},
            {KEY_I, 'i'},
            {KEY_J, 'j'},
            {KEY_K, 'k'},
            {KEY_L, 'l'},
            {KEY_M, 'm'},
            {KEY_N, 'n'},
            {KEY_O, 'o'},
            {KEY_P, 'p'},
            {KEY_Q, 'q'},
            {KEY_R, 'r'},
            {KEY_S, 's'},
            {KEY_T, 't'},
            {KEY_U, 'u'},
            {KEY_V, 'v'},
            {KEY_W, 'w'},
            {KEY_X, 'x'},
            {KEY_Y, 'y'},
            {KEY_Z, 'z'}}
        },
        {true, 
            {{KEY_ONE, '!'},
            {KEY_TWO, '@'},
            {KEY_THREE, '#'},
            {KEY_FOUR, '$'},
            {KEY_FIVE, '%'},
            {KEY_SIX, '^'},
            {KEY_SEVEN, '&'},
            {KEY_EIGHT, '*'},
            {KEY_NINE, '('},
            {KEY_ZERO, ')'},
            {KEY_MINUS, '_'},
            {KEY_EQUAL, '+'},
            {KEY_BACKSLASH, '|'},
            {KEY_COMMA, '<'},
            {KEY_PERIOD, '>'},
            {KEY_SLASH, '?'},
            {KEY_APOSTROPHE, '"'},
            {KEY_SEMICOLON, ':'},
            {KEY_LEFT_BRACKET, '{'},
            {KEY_RIGHT_BRACKET, '}'},
            {KEY_GRAVE, '~'}}
        }
    };
    int key = GetKeyPressed();
    bool shift = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT);
    printf("%lu %lu %lu %lu\n", text_.size(), line_, cursor_, text_[line_].size());
    if (key && is_in_focus_) {
        switch (key) {
            case KEY_BACKSPACE:
                if (cursor_ == 0) {
                    break;
                }
                if (cursor_ >= text_[line_].size()) {
                    text_[line_].pop_back();
                    cursor_--;
                    break;
                }
                text_[line_] = text_[line_].substr(0, cursor_) + text_[line_].substr(cursor_+1);
                cursor_--;
                break;
            case KEY_ENTER:
                line_++;
                cursor_ = 0;
                text_.push_back("");
                break;
            case KEY_LEFT_SHIFT:
            case KEY_RIGHT_SHIFT:
            case KEY_LEFT_ALT:
            case KEY_RIGHT_ALT:
            case KEY_LEFT_CONTROL:
            case KEY_RIGHT_CONTROL:
            case KEY_LEFT_SUPER:
            case KEY_RIGHT_SUPER:
            case KEY_CAPS_LOCK:
                break;
            case KEY_LEFT:
                if (cursor_ == 0) {
                    if (line_ == 0) break;
                    line_--;
                    cursor_ = text_[line_].size();
                    break;
                }
                cursor_--;
                break;
            case KEY_RIGHT:
                if (cursor_ >= text_[line_].size()) {
                    if (line_ >= text_.size() - 1) break;
                    line_++;
                    cursor_ = 0;
                    break;
                }
                cursor_++;
                break;
            case KEY_UP:
                if (line_ == 0) break;
                line_--;
                if (cursor_ >= text_[line_].size()) cursor_ = text_[line_].size(); 
                break;
            case KEY_DOWN:
                if (line_ == text_.size() - 1) break;
                line_++;
                if (cursor_ >= text_[line_].size()) cursor_ = text_[line_].size(); 
                break;
            case KEY_TAB:
                this->text_[line_].append({'\t'});
                break;
            default:
                cursor_++;
                this->text_[line_].append({
                    (charmap.at(shift).count(key)) ? 
                    charmap.at(shift).at(key) :
                    char(key)
                    });
        }
    }
}

void TextEdit::draw() {
    DrawRectangleRec(this->realbody_, WHITE);
    float font = realbody_.width*0.2;
    for (size_t i = 0; i < text_.size(); i++) {
        if (i == line_) {
            DrawTextPro(GetFontDefault(), (text_[i].substr(0, cursor_) + std::string((int(GetTime()) % 2 && is_in_focus_) ? "|" : "") + text_[i].substr(cursor_)).c_str(), {realbody_.x, realbody_.y + font*i}, {0., 0.}, 0., font, 1., BLACK);
        } else
            DrawTextPro(GetFontDefault(), text_[i].c_str(), {realbody_.x, realbody_.y + font*i}, {0., 0.}, 0., font, 1., BLACK);
    }
    // DrawTextPro(GetFontDefault(), (text_ + std::string((int(GetTime()) % 2 && is_in_focus_) ? "|" : "")).c_str(), {realbody_.x, realbody_.y}, {0., 0.}, 0., 20., 1., BLACK);
}