#pragma once
#include "Page.h"

class PageManager
{
  private:
    Page* currentPage = nullptr; // указатель на текущую страницу
    bool needRedrawstatic = false; // флаг перерисовки статики

    PageManager() = default;

  public:
    void setPage(Page* newPage);
    void update();
    Page* getCurrentPage() const;    
};
