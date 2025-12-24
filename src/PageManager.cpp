#include "PageManager.h"

class ForecastPage;
void PageManager::setPage(Page* newPage)
{
    if(newPage == nullptr) return;
    if(newPage == currentPage) return;

    currentPage = newPage;
    needRedrawstatic = true;
}

void PageManager::update()
{
    if(!currentPage) return;

    if(needRedrawstatic)
    {
        currentPage -> drawStatic();
        needRedrawstatic = false;
    }

    currentPage -> updateDinamic();
}

Page* PageManager::getCurrentPage() const
{
    return currentPage;
}