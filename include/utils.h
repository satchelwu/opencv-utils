#pragma once

#include "buffer.h"

namespace amu {

    /*void ShowTiles(cv::VideoCapture& video, const cv::Size& size) {
        int frame = video.get(CV_CAP_PROP_POS_FRAMES);
        video.set(CV_CAP_PROP_POS_FRAMES, frame - 5);
        cv::Mat image(size * 3, CV_8UC3);
        for(int x = 0; x < 3; x++) {
            for(int y = 0; y < 3; y++) {
                cv::Mat current;
                video.read(current);
                cv::Mat target(image, cv::Range(x * size.height, (x + 1) * size.height), cv::Range(y * size.width, (y + 1) * size.width));
                cv::resize(current, target, size);
            }
        }
        cv::imshow("tiles", image);
        video.set(CV_CAP_PROP_POS_FRAMES, frame);
    }

    void ShowMore(amu::Buffer<cv::Mat>& images, amu::Buffer<double>& distance, const cv::Size& size) {
        cv::Mat image(cv::Size(size.width * images.size(), size.height), CV_8UC3);
        for(int x = 0; x < images.size(); x++) {
            cv::Mat target(image, cv::Range(0 * size.height, (+ 1) * size.height), cv::Range(x * size.width, (x + 1) * size.width));
            cv::resize(images[x], target, size);
            std::stringstream value;
            value << distance[x];
            cv::putText(image, value.str(), cvPoint(10 + x * size.width, 10), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.6, cvScalar(0, 0, 255));
        }
        cv::imshow("tiles", image);
    }*/

    std::string ShowName(const std::string& filename) {
        size_t slash = filename.rfind('/');
        std::string basename;
        if(slash == std::string::npos) basename = filename;
        else basename = filename.substr(slash + 1);
        size_t dot = basename.find('.');
        if(dot == std::string::npos) return basename;
        return basename.substr(0, dot);
    }

    std::string DirName(const std::string& filename) {
        size_t slash = filename.rfind('/');
        if(slash == std::string::npos) return filename;
        return filename.substr(0, slash + 1);
    }

    // trim from start
    inline std::string &LTrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
    }

    // trim from end
    inline std::string &RTrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
    }

    // trim from both ends
    inline std::string &Trim(std::string &s) {
        return LTrim(RTrim(s));
    }

    bool StartsWith(const std::string& line, const std::string& pattern) {
        return line.substr(0, pattern.length()) == pattern;
    }

    int ParseInt(const std::string& text) {
        int output;
        std::stringstream parser(text);
        parser >> output;
        return output;
    }

}
