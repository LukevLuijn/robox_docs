//
// Created by luke on 17-05-22.
//

#ifndef ROBOX_USER_INTERFACE_BITMAP_H
#define ROBOX_USER_INTERFACE_BITMAP_H

#include "wx/bitmap.h"
#include "global_config.h"

namespace Utils
{
    class Bitmap
    {
    public:
        static wxBitmap CreateBitmap(const std::string& filename, const wxSize& size, bool fromAssets = true)
        {
            wxBitmap bitmap((fromAssets) ? std::string(ASSETS_PATH) + filename : filename);
            wxImage image = bitmap.ConvertToImage();
            image.Rescale(size.GetWidth(), size.GetHeight(), wxIMAGE_QUALITY_HIGH);
            return wxBitmap(image);
        }
        static wxBitmap CreateBitmap(const std::string& filename, uint16_t width, uint16_t height, bool fromAssets = true)
        {
            return CreateBitmap(filename, wxSize(width, height), fromAssets);
        }

    };
}

#endif//ROBOX_USER_INTERFACE_BITMAP_H
