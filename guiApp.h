/***************************************************************
 * Name:      guiApp.h
 * Purpose:   Defines Application Class
 * Author:    Jonas Zinn (Jonas.S.Zinn@gmail.com)
 * Created:   2014-10-18
 * Copyright: Jonas Zinn ()
 * License:
 **************************************************************/

#ifndef GUIAPP_H
#define GUIAPP_H

#include <wx/app.h>

class guiApp : public wxApp
{
    public:
        virtual bool OnInit();
		~guiApp();
};

#endif // GUIAPP_H
