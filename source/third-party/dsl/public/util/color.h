#pragma once

#include "util/types.h"

#include <array>
#include <ostream>

namespace dsl
{
    template <typename T>
    struct color_3
    {
      static_assert(std::is_arithmetic_v<T>, "t must be of arithemetic type");

      constexpr color_3()
          : red(t())
          , green(t())
          , blue(t())
      {
      }

      constexpr color_3(t r, t g, t b)
          : red(r)
          , green(g)
          , blue(b)
      {
      }

      constexpr t* data()
      {
        return color_data.data();
      }
      constexpr const t* data() const
      {
        return color_data.data();
      }

      constexpr color_3& clamp(t min, t max)
      {
        *this = clamped(min, max);

        return *this;
      }
      constexpr color_3& clamped(t min, t max)
      {
        color_3 temp = *this;

        temp.red   = clamp(red, min, max);
        temp.green = clamp(green, min, max);
        temp.blue  = clamp(blue, min, max);

        return temp;
      }

      constexpr color_3 operator*(t brightness) const
      {
        color_3 tmp = *this;
        tmp.red *= brightness;
        tmp.green *= brightness;
        tmp.blue *= brightness;

        return tmp;
      }
      constexpr color_3 operator/(t brightness) const
      {
        color_3 tmp = *this;
        tmp.red /= brightness;
        tmp.green /= brightness;
        tmp.blue /= brightness;

        return tmp;
      }
      constexpr color_3& operator*(t brightness)
      {
        red *= brightness;
        green *= brightness;
        blue *= brightness;

        return *this;
      }
      constexpr color_3& operator/(t brightness)
      {
        red /= brightness;
        green /= brightness;
        blue /= brightness;

        return *this;
      }

      union
      {
        // disabling this warning because it has to be nameless.
#pragma warning(push)
#pragma warning(disable : 4201)
        struct
        {
          t red, green, blue;
        };
#pragma warning(pop)
        std::array<t, 3> color_data;
      };
    };

    template <typename T, typename U>
    T to_custom_color3(const color_3<U>& color)
    {
      static_assert(sizeof(t) == sizeof(color_3<U>), "sizeof custom color must be equal to color_3");
      t custom_color;
      memcpy(&custom_color, &color, sizeof(color));
      return custom_color;
    }

    template <typename T, typename U>
    color_3<T> to_rex_color3(const U& custom_color)
    {
      static_assert(sizeof(t) == sizeof(color_3<U>), "sizeof custom color must be equal to color_3");
      color_3<T> color;
      memcpy(&color, &custom_color, sizeof(custom_color));
      return color;
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const color_3<T>& color)
    {
      os << "(r: " << color.red << ", g: " << color.green << ", b: " << color.blue << ")";
      return os;
    }

    template <typename T>
    struct color_4
    {
      constexpr color_4()
          : red(T())
          , green(T())
          , blue(T())
          , alpha(T(1))
      {
      }

      constexpr color_4(t r, t g, t b, t a = 1.0f)
          : red(r)
          , green(g)
          , blue(b)
          , alpha(a)
      {
      }

      t* data()
      {
        return color_data.data();
      }
      const t* data() const
      {
        return color_data.data();
      }

      constexpr color_4& clamp(t min, t max)
      {
        *this = clamped(min, max);

        return *this;
      }
      constexpr color_4& clamped(t min, t max)
      {
        color_4 temp = *this;

        temp.red   = clamp(red, min, max);
        temp.green = clamp(green, min, max);
        temp.blue  = clamp(blue, min, max);

        return temp;
      }

      constexpr color_4 operator*(t brightness) const
      {
        color_4 tmp = *this;
        tmp.red *= brightness;
        tmp.green *= brightness;
        tmp.blue *= brightness;

        return tmp;
      }
      constexpr color_4 operator/(t brightness) const
      {
        color_4 tmp = *this;
        tmp.red /= brightness;
        tmp.green /= brightness;
        tmp.blue /= brightness;

        return tmp;
      }
      constexpr color_4& operator*(t brightness)
      {
        red *= brightness;
        green *= brightness;
        blue *= brightness;

        return *this;
      }
      constexpr color_4& operator/(t brightness)
      {
        red /= brightness;
        green /= brightness;
        blue /= brightness;

        return *this;
      }

      union
      {
        // disabling this warning because it has to be nameless.
#pragma warning(push)
#pragma warning(disable : 4201)
        struct
        {
          t red, green, blue, alpha;
        };
#pragma warning(pop)
        std::array<T, 4> color_data;
      };
    };

    template <typename T, typename U>
    T to_custom_color4(const color_4<U>& color)
    {
      static_assert(sizeof(t) == sizeof(color_4<U>), "sizeof custom color must be equal to color_4");
      t custom_color;
      memcpy(&custom_color, &color, sizeof(color));
      return custom_color;
    }

    template <typename T, typename U>
    color_4<T> to_rex_color4(const U& custom_color)
    {
      static_assert(sizeof(t) == sizeof(color_4<U>), "sizeof custom color must be equal to color_4");
      color_4<T> color;
      memcpy(&color, &custom_color, sizeof(custom_color));
      return color;
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const color_4<T>& color)
    {
      os << "(r: " << color.red << ", g: " << color.green << ", b: " << color.blue << ", a: " << color.alpha << ")";
      return os;
    }

    using rgb  = color_3<u8>;
    using rgba = color_4<u8>;

    using color_3f = color_3<f32>;
    using color_4f = color_4<f32>;

    namespace colors
    {
      constexpr color_4f alice_blue(0.941176534f, 0.972549081f, 1.000000000f, 1.000000000f);
      constexpr color_4f antique_white(0.980392218f, 0.921568692f, 0.843137324f, 1.000000000f);
      constexpr color_4f aqua(0.000000000f, 1.000000000f, 1.000000000f, 1.000000000f);
      constexpr color_4f aquamarine(0.498039246f, 1.000000000f, 0.831372619f, 1.000000000f);
      constexpr color_4f azure(0.941176534f, 1.000000000f, 1.000000000f, 1.000000000f);
      constexpr color_4f beige(0.960784376f, 0.960784376f, 0.862745166f, 1.000000000f);
      constexpr color_4f bisque(1.000000000f, 0.894117713f, 0.768627524f, 1.000000000f);
      constexpr color_4f black(0.000000000f, 0.000000000f, 0.000000000f, 1.000000000f);
      constexpr color_4f blanched_almond(1.000000000f, 0.921568692f, 0.803921640f, 1.000000000f);
      constexpr color_4f blue(0.000000000f, 0.000000000f, 1.000000000f, 1.000000000f);
      constexpr color_4f blue_violet(0.541176498f, 0.168627456f, 0.886274576f, 1.000000000f);
      constexpr color_4f brown(0.647058845f, 0.164705887f, 0.164705887f, 1.000000000f);
      constexpr color_4f burly_wood(0.870588303f, 0.721568644f, 0.529411793f, 1.000000000f);
      constexpr color_4f cadet_blue(0.372549027f, 0.619607866f, 0.627451003f, 1.000000000f);
      constexpr color_4f chartreuse(0.498039246f, 1.000000000f, 0.000000000f, 1.000000000f);
      constexpr color_4f chocolate(0.823529482f, 0.411764741f, 0.117647067f, 1.000000000f);
      constexpr color_4f coral(1.000000000f, 0.498039246f, 0.313725501f, 1.000000000f);
      constexpr color_4f cornflower_blue(0.392156899f, 0.584313750f, 0.929411829f, 1.000000000f);
      constexpr color_4f cornsilk(1.000000000f, 0.972549081f, 0.862745166f, 1.000000000f);
      constexpr color_4f crimson(0.862745166f, 0.078431375f, 0.235294133f, 1.000000000f);
      constexpr color_4f cyan(0.000000000f, 1.000000000f, 1.000000000f, 1.000000000f);
      constexpr color_4f dark_blue(0.000000000f, 0.000000000f, 0.545098066f, 1.000000000f);
      constexpr color_4f dark_cyan(0.000000000f, 0.545098066f, 0.545098066f, 1.000000000f);
      constexpr color_4f dark_goldenrod(0.721568644f, 0.525490224f, 0.043137256f, 1.000000000f);
      constexpr color_4f dark_gray(0.662745118f, 0.662745118f, 0.662745118f, 1.000000000f);
      constexpr color_4f dark_green(0.000000000f, 0.392156899f, 0.000000000f, 1.000000000f);
      constexpr color_4f dark_khaki(0.741176486f, 0.717647076f, 0.419607878f, 1.000000000f);
      constexpr color_4f dark_magenta(0.545098066f, 0.000000000f, 0.545098066f, 1.000000000f);
      constexpr color_4f dark_olive_green(0.333333343f, 0.419607878f, 0.184313729f, 1.000000000f);
      constexpr color_4f dark_orange(1.000000000f, 0.549019635f, 0.000000000f, 1.000000000f);
      constexpr color_4f dark_orchid(0.600000024f, 0.196078449f, 0.800000072f, 1.000000000f);
      constexpr color_4f dark_red(0.545098066f, 0.000000000f, 0.000000000f, 1.000000000f);
      constexpr color_4f dark_salmon(0.913725555f, 0.588235319f, 0.478431404f, 1.000000000f);
      constexpr color_4f dark_sea_green(0.560784340f, 0.737254918f, 0.545098066f, 1.000000000f);
      constexpr color_4f dark_slate_blue(0.282352954f, 0.239215702f, 0.545098066f, 1.000000000f);
      constexpr color_4f dark_slate_gray(0.184313729f, 0.309803933f, 0.309803933f, 1.000000000f);
      constexpr color_4f dark_turquoise(0.000000000f, 0.807843208f, 0.819607913f, 1.000000000f);
      constexpr color_4f dark_violet(0.580392182f, 0.000000000f, 0.827451050f, 1.000000000f);
      constexpr color_4f deep_pink(1.000000000f, 0.078431375f, 0.576470613f, 1.000000000f);
      constexpr color_4f deep_sky_blue(0.000000000f, 0.749019623f, 1.000000000f, 1.000000000f);
      constexpr color_4f dim_gray(0.411764741f, 0.411764741f, 0.411764741f, 1.000000000f);
      constexpr color_4f dodger_blue(0.117647067f, 0.564705908f, 1.000000000f, 1.000000000f);
      constexpr color_4f firebrick(0.698039234f, 0.133333340f, 0.133333340f, 1.000000000f);
      constexpr color_4f floral_white(1.000000000f, 0.980392218f, 0.941176534f, 1.000000000f);
      constexpr color_4f forest_green(0.133333340f, 0.545098066f, 0.133333340f, 1.000000000f);
      constexpr color_4f fuchsia(1.000000000f, 0.000000000f, 1.000000000f, 1.000000000f);
      constexpr color_4f gainsboro(0.862745166f, 0.862745166f, 0.862745166f, 1.000000000f);
      constexpr color_4f ghost_white(0.972549081f, 0.972549081f, 1.000000000f, 1.000000000f);
      constexpr color_4f gold(1.000000000f, 0.843137324f, 0.000000000f, 1.000000000f);
      constexpr color_4f goldenrod(0.854902029f, 0.647058845f, 0.125490203f, 1.000000000f);
      constexpr color_4f gray(0.501960814f, 0.501960814f, 0.501960814f, 1.000000000f);
      constexpr color_4f green(0.000000000f, 0.501960814f, 0.000000000f, 1.000000000f);
      constexpr color_4f green_yellow(0.678431392f, 1.000000000f, 0.184313729f, 1.000000000f);
      constexpr color_4f honeydew(0.941176534f, 1.000000000f, 0.941176534f, 1.000000000f);
      constexpr color_4f hot_pink(1.000000000f, 0.411764741f, 0.705882370f, 1.000000000f);
      constexpr color_4f indian_red(0.803921640f, 0.360784322f, 0.360784322f, 1.000000000f);
      constexpr color_4f indigo(0.294117659f, 0.000000000f, 0.509803951f, 1.000000000f);
      constexpr color_4f ivory(1.000000000f, 1.000000000f, 0.941176534f, 1.000000000f);
      constexpr color_4f khaki(0.941176534f, 0.901960850f, 0.549019635f, 1.000000000f);
      constexpr color_4f lavender(0.901960850f, 0.901960850f, 0.980392218f, 1.000000000f);
      constexpr color_4f lavender_blush(1.000000000f, 0.941176534f, 0.960784376f, 1.000000000f);
      constexpr color_4f lawn_green(0.486274540f, 0.988235354f, 0.000000000f, 1.000000000f);
      constexpr color_4f lemon_chiffon(1.000000000f, 0.980392218f, 0.803921640f, 1.000000000f);
      constexpr color_4f light_blue(0.678431392f, 0.847058892f, 0.901960850f, 1.000000000f);
      constexpr color_4f light_coral(0.941176534f, 0.501960814f, 0.501960814f, 1.000000000f);
      constexpr color_4f light_cyan(0.878431439f, 1.000000000f, 1.000000000f, 1.000000000f);
      constexpr color_4f light_goldenrod_yellow(0.980392218f, 0.980392218f, 0.823529482f, 1.000000000f);
      constexpr color_4f light_green(0.564705908f, 0.933333397f, 0.564705908f, 1.000000000f);
      constexpr color_4f light_gray(0.827451050f, 0.827451050f, 0.827451050f, 1.000000000f);
      constexpr color_4f light_pink(1.000000000f, 0.713725507f, 0.756862819f, 1.000000000f);
      constexpr color_4f light_salmon(1.000000000f, 0.627451003f, 0.478431404f, 1.000000000f);
      constexpr color_4f light_sea_green(0.125490203f, 0.698039234f, 0.666666687f, 1.000000000f);
      constexpr color_4f light_sky_blue(0.529411793f, 0.807843208f, 0.980392218f, 1.000000000f);
      constexpr color_4f light_slate_gray(0.466666698f, 0.533333361f, 0.600000024f, 1.000000000f);
      constexpr color_4f light_steel_blue(0.690196097f, 0.768627524f, 0.870588303f, 1.000000000f);
      constexpr color_4f light_yellow(1.000000000f, 1.000000000f, 0.878431439f, 1.000000000f);
      constexpr color_4f lime(0.000000000f, 1.000000000f, 0.000000000f, 1.000000000f);
      constexpr color_4f lime_green(0.196078449f, 0.803921640f, 0.196078449f, 1.000000000f);
      constexpr color_4f linen(0.980392218f, 0.941176534f, 0.901960850f, 1.000000000f);
      constexpr color_4f magenta(1.000000000f, 0.000000000f, 1.000000000f, 1.000000000f);
      constexpr color_4f maroon(0.501960814f, 0.000000000f, 0.000000000f, 1.000000000f);
      constexpr color_4f medium_aquamarine(0.400000036f, 0.803921640f, 0.666666687f, 1.000000000f);
      constexpr color_4f medium_blue(0.000000000f, 0.000000000f, 0.803921640f, 1.000000000f);
      constexpr color_4f medium_orchid(0.729411781f, 0.333333343f, 0.827451050f, 1.000000000f);
      constexpr color_4f medium_purple(0.576470613f, 0.439215720f, 0.858823597f, 1.000000000f);
      constexpr color_4f medium_sea_green(0.235294133f, 0.701960802f, 0.443137288f, 1.000000000f);
      constexpr color_4f medium_slate_blue(0.482352972f, 0.407843173f, 0.933333397f, 1.000000000f);
      constexpr color_4f medium_spring_green(0.000000000f, 0.980392218f, 0.603921592f, 1.000000000f);
      constexpr color_4f medium_turquoise(0.282352954f, 0.819607913f, 0.800000072f, 1.000000000f);
      constexpr color_4f medium_violet_red(0.780392230f, 0.082352944f, 0.521568656f, 1.000000000f);
      constexpr color_4f midnight_blue(0.098039225f, 0.098039225f, 0.439215720f, 1.000000000f);
      constexpr color_4f mint_cream(0.960784376f, 1.000000000f, 0.980392218f, 1.000000000f);
      constexpr color_4f misty_rose(1.000000000f, 0.894117713f, 0.882353008f, 1.000000000f);
      constexpr color_4f moccasin(1.000000000f, 0.894117713f, 0.709803939f, 1.000000000f);
      constexpr color_4f navajo_white(1.000000000f, 0.870588303f, 0.678431392f, 1.000000000f);
      constexpr color_4f navy(0.000000000f, 0.000000000f, 0.501960814f, 1.000000000f);
      constexpr color_4f old_lace(0.992156923f, 0.960784376f, 0.901960850f, 1.000000000f);
      constexpr color_4f olive(0.501960814f, 0.501960814f, 0.000000000f, 1.000000000f);
      constexpr color_4f olive_drab(0.419607878f, 0.556862772f, 0.137254909f, 1.000000000f);
      constexpr color_4f orange(1.000000000f, 0.647058845f, 0.000000000f, 1.000000000f);
      constexpr color_4f orange_red(1.000000000f, 0.270588249f, 0.000000000f, 1.000000000f);
      constexpr color_4f orchid(0.854902029f, 0.439215720f, 0.839215755f, 1.000000000f);
      constexpr color_4f pale_goldenrod(0.933333397f, 0.909803987f, 0.666666687f, 1.000000000f);
      constexpr color_4f pale_green(0.596078455f, 0.984313786f, 0.596078455f, 1.000000000f);
      constexpr color_4f pale_turquoise(0.686274529f, 0.933333397f, 0.933333397f, 1.000000000f);
      constexpr color_4f pale_violet_red(0.858823597f, 0.439215720f, 0.576470613f, 1.000000000f);
      constexpr color_4f papaya_whip(1.000000000f, 0.937254965f, 0.835294187f, 1.000000000f);
      constexpr color_4f peach_puff(1.000000000f, 0.854902029f, 0.725490212f, 1.000000000f);
      constexpr color_4f peru(0.803921640f, 0.521568656f, 0.247058839f, 1.000000000f);
      constexpr color_4f pink(1.000000000f, 0.752941251f, 0.796078503f, 1.000000000f);
      constexpr color_4f plum(0.866666734f, 0.627451003f, 0.866666734f, 1.000000000f);
      constexpr color_4f powder_blue(0.690196097f, 0.878431439f, 0.901960850f, 1.000000000f);
      constexpr color_4f purple(0.501960814f, 0.000000000f, 0.501960814f, 1.000000000f);
      constexpr color_4f red(1.000000000f, 0.000000000f, 0.000000000f, 1.000000000f);
      constexpr color_4f rosy_brown(0.737254918f, 0.560784340f, 0.560784340f, 1.000000000f);
      constexpr color_4f royal_blue(0.254901975f, 0.411764741f, 0.882353008f, 1.000000000f);
      constexpr color_4f saddle_brown(0.545098066f, 0.270588249f, 0.074509807f, 1.000000000f);
      constexpr color_4f salmon(0.980392218f, 0.501960814f, 0.447058856f, 1.000000000f);
      constexpr color_4f sandy_brown(0.956862807f, 0.643137276f, 0.376470625f, 1.000000000f);
      constexpr color_4f sea_green(0.180392161f, 0.545098066f, 0.341176480f, 1.000000000f);
      constexpr color_4f sea_shell(1.000000000f, 0.960784376f, 0.933333397f, 1.000000000f);
      constexpr color_4f sienna(0.627451003f, 0.321568638f, 0.176470593f, 1.000000000f);
      constexpr color_4f silver(0.752941251f, 0.752941251f, 0.752941251f, 1.000000000f);
      constexpr color_4f sky_blue(0.529411793f, 0.807843208f, 0.921568692f, 1.000000000f);
      constexpr color_4f slate_blue(0.415686309f, 0.352941185f, 0.803921640f, 1.000000000f);
      constexpr color_4f slate_gray(0.439215720f, 0.501960814f, 0.564705908f, 1.000000000f);
      constexpr color_4f snow(1.000000000f, 0.980392218f, 0.980392218f, 1.000000000f);
      constexpr color_4f spring_green(0.000000000f, 1.000000000f, 0.498039246f, 1.000000000f);
      constexpr color_4f steel_blue(0.274509817f, 0.509803951f, 0.705882370f, 1.000000000f);
      constexpr color_4f tan(0.823529482f, 0.705882370f, 0.549019635f, 1.000000000f);
      constexpr color_4f teal(0.000000000f, 0.501960814f, 0.501960814f, 1.000000000f);
      constexpr color_4f thistle(0.847058892f, 0.749019623f, 0.847058892f, 1.000000000f);
      constexpr color_4f tomato(1.000000000f, 0.388235331f, 0.278431386f, 1.000000000f);
      constexpr color_4f transparent(0.000000000f, 0.000000000f, 0.000000000f, 0.000000000f);
      constexpr color_4f turquoise(0.250980407f, 0.878431439f, 0.815686345f, 1.000000000f);
      constexpr color_4f violet(0.933333397f, 0.509803951f, 0.933333397f, 1.000000000f);
      constexpr color_4f wheat(0.960784376f, 0.870588303f, 0.701960802f, 1.000000000f);
      constexpr color_4f white(1.000000000f, 1.000000000f, 1.000000000f, 1.000000000f);
      constexpr color_4f white_smoke(0.960784376f, 0.960784376f, 0.960784376f, 1.000000000f);
      constexpr color_4f yellow(1.000000000f, 1.000000000f, 0.000000000f, 1.000000000f);
      constexpr color_4f yellow_green(0.603921592f, 0.803921640f, 0.196078449f, 1.000000000f);
    } // namespace colors

    namespace rgba_colors
    {
      constexpr rgba color4f_to_rgba(const color_4f& color)
      {
        rgba rgba;
        rgba.red   = static_cast<u8>(255 * color.red);
        rgba.green = static_cast<u8>(255 * color.green);
        rgba.blue  = static_cast<u8>(255 * color.blue);
        rgba.alpha = static_cast<u8>(255 * color.alpha);

        return rgba;
      }

      constexpr rgba alice_blue            = color4f_to_rgba(colors::alice_blue);
      constexpr rgba antique_white         = color4f_to_rgba(colors::antique_white);
      constexpr rgba aqua                 = color4f_to_rgba(colors::aqua);
      constexpr rgba aquamarine           = color4f_to_rgba(colors::aquamarine);
      constexpr rgba azure                = color4f_to_rgba(colors::azure);
      constexpr rgba beige                = color4f_to_rgba(colors::beige);
      constexpr rgba bisque               = color4f_to_rgba(colors::bisque);
      constexpr rgba black                = color4f_to_rgba(colors::black);
      constexpr rgba blanched_almond       = color4f_to_rgba(colors::blanched_almond);
      constexpr rgba blue                 = color4f_to_rgba(colors::blue);
      constexpr rgba blue_violet           = color4f_to_rgba(colors::blue_violet);
      constexpr rgba brown                = color4f_to_rgba(colors::brown);
      constexpr rgba burly_wood            = color4f_to_rgba(colors::burly_wood);
      constexpr rgba cadet_blue            = color4f_to_rgba(colors::cadet_blue);
      constexpr rgba chartreuse           = color4f_to_rgba(colors::chartreuse);
      constexpr rgba chocolate            = color4f_to_rgba(colors::chocolate);
      constexpr rgba coral                = color4f_to_rgba(colors::coral);
      constexpr rgba cornflower_blue       = color4f_to_rgba(colors::cornflower_blue);
      constexpr rgba cornsilk             = color4f_to_rgba(colors::cornsilk);
      constexpr rgba crimson              = color4f_to_rgba(colors::crimson);
      constexpr rgba cyan                 = color4f_to_rgba(colors::cyan);
      constexpr rgba dark_blue             = color4f_to_rgba(colors::dark_blue);
      constexpr rgba dark_cyan             = color4f_to_rgba(colors::dark_cyan);
      constexpr rgba dark_goldenrod        = color4f_to_rgba(colors::dark_goldenrod);
      constexpr rgba dark_gray             = color4f_to_rgba(colors::dark_gray);
      constexpr rgba dark_green            = color4f_to_rgba(colors::dark_green);
      constexpr rgba dark_khaki            = color4f_to_rgba(colors::dark_khaki);
      constexpr rgba dark_magenta          = color4f_to_rgba(colors::dark_magenta);
      constexpr rgba dark_olive_green       = color4f_to_rgba(colors::dark_olive_green);
      constexpr rgba dark_orange           = color4f_to_rgba(colors::dark_orange);
      constexpr rgba dark_orchid           = color4f_to_rgba(colors::dark_orchid);
      constexpr rgba dark_red              = color4f_to_rgba(colors::dark_red);
      constexpr rgba dark_salmon           = color4f_to_rgba(colors::dark_salmon);
      constexpr rgba dark_sea_green         = color4f_to_rgba(colors::dark_sea_green);
      constexpr rgba dark_slate_blue        = color4f_to_rgba(colors::dark_slate_blue);
      constexpr rgba dark_slate_gray        = color4f_to_rgba(colors::dark_slate_gray);
      constexpr rgba dark_turquoise        = color4f_to_rgba(colors::dark_turquoise);
      constexpr rgba dark_violet           = color4f_to_rgba(colors::dark_violet);
      constexpr rgba deep_pink             = color4f_to_rgba(colors::deep_pink);
      constexpr rgba deep_sky_blue          = color4f_to_rgba(colors::deep_sky_blue);
      constexpr rgba dim_gray              = color4f_to_rgba(colors::dim_gray);
      constexpr rgba dodger_blue           = color4f_to_rgba(colors::dodger_blue);
      constexpr rgba firebrick            = color4f_to_rgba(colors::firebrick);
      constexpr rgba floral_white          = color4f_to_rgba(colors::floral_white);
      constexpr rgba forest_green          = color4f_to_rgba(colors::forest_green);
      constexpr rgba fuchsia              = color4f_to_rgba(colors::fuchsia);
      constexpr rgba gainsboro            = color4f_to_rgba(colors::gainsboro);
      constexpr rgba ghost_white           = color4f_to_rgba(colors::ghost_white);
      constexpr rgba gold                 = color4f_to_rgba(colors::gold);
      constexpr rgba goldenrod            = color4f_to_rgba(colors::goldenrod);
      constexpr rgba gray                 = color4f_to_rgba(colors::gray);
      constexpr rgba green                = color4f_to_rgba(colors::green);
      constexpr rgba green_yellow          = color4f_to_rgba(colors::green_yellow);
      constexpr rgba honeydew             = color4f_to_rgba(colors::honeydew);
      constexpr rgba hot_pink              = color4f_to_rgba(colors::hot_pink);
      constexpr rgba indian_red            = color4f_to_rgba(colors::indian_red);
      constexpr rgba indigo               = color4f_to_rgba(colors::indigo);
      constexpr rgba ivory                = color4f_to_rgba(colors::ivory);
      constexpr rgba khaki                = color4f_to_rgba(colors::khaki);
      constexpr rgba lavender             = color4f_to_rgba(colors::lavender);
      constexpr rgba lavender_blush        = color4f_to_rgba(colors::lavender_blush);
      constexpr rgba lawn_green            = color4f_to_rgba(colors::lawn_green);
      constexpr rgba lemon_chiffon         = color4f_to_rgba(colors::lemon_chiffon);
      constexpr rgba light_blue            = color4f_to_rgba(colors::light_blue);
      constexpr rgba light_coral           = color4f_to_rgba(colors::light_coral);
      constexpr rgba light_cyan            = color4f_to_rgba(colors::light_cyan);
      constexpr rgba light_goldenrod_yellow = color4f_to_rgba(colors::light_goldenrod_yellow);
      constexpr rgba light_green           = color4f_to_rgba(colors::light_green);
      constexpr rgba light_gray            = color4f_to_rgba(colors::light_gray);
      constexpr rgba light_pink            = color4f_to_rgba(colors::light_pink);
      constexpr rgba light_salmon          = color4f_to_rgba(colors::light_salmon);
      constexpr rgba light_sea_green        = color4f_to_rgba(colors::light_sea_green);
      constexpr rgba light_sky_blue         = color4f_to_rgba(colors::light_sky_blue);
      constexpr rgba light_slate_gray       = color4f_to_rgba(colors::light_slate_gray);
      constexpr rgba light_steel_blue       = color4f_to_rgba(colors::light_steel_blue);
      constexpr rgba light_yellow          = color4f_to_rgba(colors::light_yellow);
      constexpr rgba lime                 = color4f_to_rgba(colors::lime);
      constexpr rgba lime_green            = color4f_to_rgba(colors::lime_green);
      constexpr rgba linen                = color4f_to_rgba(colors::linen);
      constexpr rgba magenta              = color4f_to_rgba(colors::magenta);
      constexpr rgba maroon               = color4f_to_rgba(colors::maroon);
      constexpr rgba medium_aquamarine     = color4f_to_rgba(colors::medium_aquamarine);
      constexpr rgba medium_blue           = color4f_to_rgba(colors::medium_blue);
      constexpr rgba medium_orchid         = color4f_to_rgba(colors::medium_orchid);
      constexpr rgba medium_purple         = color4f_to_rgba(colors::medium_purple);
      constexpr rgba medium_sea_green       = color4f_to_rgba(colors::medium_sea_green);
      constexpr rgba medium_slate_blue      = color4f_to_rgba(colors::medium_slate_blue);
      constexpr rgba medium_spring_green    = color4f_to_rgba(colors::medium_spring_green);
      constexpr rgba medium_turquoise      = color4f_to_rgba(colors::medium_turquoise);
      constexpr rgba medium_violet_red      = color4f_to_rgba(colors::medium_violet_red);
      constexpr rgba midnight_blue         = color4f_to_rgba(colors::midnight_blue);
      constexpr rgba mint_cream            = color4f_to_rgba(colors::mint_cream);
      constexpr rgba misty_rose            = color4f_to_rgba(colors::misty_rose);
      constexpr rgba moccasin             = color4f_to_rgba(colors::moccasin);
      constexpr rgba navajo_white          = color4f_to_rgba(colors::navajo_white);
      constexpr rgba navy                 = color4f_to_rgba(colors::navy);
      constexpr rgba old_lace              = color4f_to_rgba(colors::old_lace);
      constexpr rgba olive                = color4f_to_rgba(colors::olive);
      constexpr rgba olive_drab            = color4f_to_rgba(colors::olive_drab);
      constexpr rgba orange               = color4f_to_rgba(colors::orange);
      constexpr rgba orange_red            = color4f_to_rgba(colors::orange_red);
      constexpr rgba orchid               = color4f_to_rgba(colors::orchid);
      constexpr rgba pale_goldenrod        = color4f_to_rgba(colors::pale_goldenrod);
      constexpr rgba pale_green            = color4f_to_rgba(colors::pale_green);
      constexpr rgba pale_turquoise        = color4f_to_rgba(colors::pale_turquoise);
      constexpr rgba pale_violet_red        = color4f_to_rgba(colors::pale_violet_red);
      constexpr rgba papaya_whip           = color4f_to_rgba(colors::papaya_whip);
      constexpr rgba peach_puff            = color4f_to_rgba(colors::peach_puff);
      constexpr rgba peru                 = color4f_to_rgba(colors::peru);
      constexpr rgba pink                 = color4f_to_rgba(colors::pink);
      constexpr rgba plum                 = color4f_to_rgba(colors::plum);
      constexpr rgba powder_blue           = color4f_to_rgba(colors::powder_blue);
      constexpr rgba purple               = color4f_to_rgba(colors::purple);
      constexpr rgba red                  = color4f_to_rgba(colors::red);
      constexpr rgba rosy_brown            = color4f_to_rgba(colors::rosy_brown);
      constexpr rgba royal_blue            = color4f_to_rgba(colors::royal_blue);
      constexpr rgba saddle_brown          = color4f_to_rgba(colors::saddle_brown);
      constexpr rgba salmon               = color4f_to_rgba(colors::salmon);
      constexpr rgba sandy_brown           = color4f_to_rgba(colors::sandy_brown);
      constexpr rgba sea_green             = color4f_to_rgba(colors::sea_green);
      constexpr rgba sea_shell             = color4f_to_rgba(colors::sea_shell);
      constexpr rgba sienna               = color4f_to_rgba(colors::sienna);
      constexpr rgba silver               = color4f_to_rgba(colors::silver);
      constexpr rgba sky_blue              = color4f_to_rgba(colors::sky_blue);
      constexpr rgba slate_blue            = color4f_to_rgba(colors::slate_blue);
      constexpr rgba slate_gray            = color4f_to_rgba(colors::slate_gray);
      constexpr rgba snow                 = color4f_to_rgba(colors::snow);
      constexpr rgba spring_green          = color4f_to_rgba(colors::spring_green);
      constexpr rgba steel_blue            = color4f_to_rgba(colors::steel_blue);
      constexpr rgba tan                  = color4f_to_rgba(colors::tan);
      constexpr rgba teal                 = color4f_to_rgba(colors::teal);
      constexpr rgba thistle              = color4f_to_rgba(colors::thistle);
      constexpr rgba tomato               = color4f_to_rgba(colors::tomato);
      constexpr rgba transparent          = color4f_to_rgba(colors::transparent);
      constexpr rgba turquoise            = color4f_to_rgba(colors::turquoise);
      constexpr rgba violet               = color4f_to_rgba(colors::violet);
      constexpr rgba wheat                = color4f_to_rgba(colors::wheat);
      constexpr rgba white                = color4f_to_rgba(colors::white);
      constexpr rgba white_smoke           = color4f_to_rgba(colors::white_smoke);
      constexpr rgba yellow               = color4f_to_rgba(colors::yellow);
      constexpr rgba yellow_green          = color4f_to_rgba(colors::yellow_green);
    } // namespace rgba_colors
} // namespace dsl