#include <iostream>
#include <format>
#include <cmath>
#include <string>   // Required for using string variables

int clamp(int value, int min, int max) {
    return std::min(std::max(value, min), max);
}

std::string my_getline() {
    std::string result;

    while (!getline(std::cin, result) || result.empty());

    return result;
}

int main() {
    int quiz_0, quiz_1, quiz_2, quiz_3, quiz_4, quiz_5;
    int activity_0, activity_1, activity_2;
    int majorexam_0, majorexam_1, majorexam_2;
    int usn;
    std::string name;
    
    std::cout << "Enter USN:\n";
    std::cin >> usn;
    
    std::cout << "Enter Full Name:\n";
    std::cin >> name;
    
    std::cout << "Enter quiz scores (2 Prelim -> 2 Midterm -> 2 Finals):\n";
    std::cin >> quiz_0 >> quiz_1 >> quiz_2 >> quiz_3 >> quiz_4 >> quiz_5;
    quiz_0 = clamp(quiz_0, 50, 100);
    quiz_1 = clamp(quiz_1, 50, 100);
    quiz_2 = clamp(quiz_2, 50, 100);
    quiz_3 = clamp(quiz_3, 50, 100);
    quiz_4 = clamp(quiz_4, 50, 100);
    quiz_5 = clamp(quiz_5, 50, 100);

    std::cout << "Enter activity scores (Prelim -> Midterm -> Finals):\n";
    std::cin >> activity_0 >> activity_1 >> activity_2;
    activity_0 = clamp(activity_0, 0, 100);
    activity_1 = clamp(activity_1, 0, 100);
    activity_2 = clamp(activity_2, 0, 100);

    std::cout << "Enter major exam scores (Prelim -> Midterm -> Finals):\n";
    std::cin >> majorexam_0 >> majorexam_1 >> majorexam_2;
    majorexam_0 = clamp(majorexam_0, 0, 100);
    majorexam_1 = clamp(majorexam_1, 0, 100);
    majorexam_2 = clamp(majorexam_2, 0, 100);
    
    float quizfinal = (float)(quiz_0 + quiz_1 + quiz_2 + quiz_3 + quiz_4 + quiz_5) / 600.0f;

    float activityfinal = 1.0f;//(float)(activity_0 + activity_1 + activity_2) / 300.0f;

    float majorexamfinal = (float)(majorexam_0 + majorexam_1 + majorexam_2) / 300.0f;
    
    float lmsfinal = (quizfinal + majorexamfinal) * 25.0f;
    float facetofacefinal = (activityfinal + majorexamfinal) * 25.0f;

    //float gradefinal = (activityfinal + facetofacefinal) / 2.0f;
    
    std::cout << "\n--== Grade Results ==--\n";
    
    std::cout << "> Quiz:       " << (int)(quizfinal * 50.0f) << " / 50\n";
    std::cout << "> Major Exam: " << (int)(majorexamfinal * 50.0f) << "  / 50 +\n                   ";
    std::cout << (quizfinal + majorexamfinal) * 25.0f << " % <-- LMS Grade\n\n";
    
    
    std::cout << "> Activity:   " << (int)(quizfinal * 50.0f) << " / 50\n";
    std::cout << "> Major Exam: " << (int)(majorexamfinal * 50.0f) << "  / 50 +\n                   ";
    std::cout << facetofacefinal << " % <-- F2F Grade\n\n";
    
    int gradefinal = floor((double)(lmsfinal + facetofacefinal));
    std::cout << "\nFinal Grade --> " << facetofacefinal << " + " << (int)lmsfinal << " = " << (int)gradefinal<<"%\n";

    if (gradefinal >= 75.0f) {
        std::cout << "Passed\n";
    } else std::cout << "Failed\n";
    

    return 0;
}
