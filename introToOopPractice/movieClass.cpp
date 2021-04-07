#include <iostream>
#include <string>
using namespace std;

class Movie {
    string name;
    string mpaaRating;
    int oneStarRatings;
    int twoStarRatings;
    int threeStarRatings;
    int fourStarRatings;
    int fiveStarRatings;
public:
    Movie(string movie, string rating): name(movie), mpaaRating(rating), oneStarRatings(0), twoStarRatings(0), threeStarRatings(0), fourStarRatings(0), fiveStarRatings(0) {};
    Movie(string movie, string rating, int oneStar, int twoStar, int threeStar, int fourStar, int fiveStar);

    void addRating(int rating);
    double getAverage();

    friend ostream& operator<<(ostream& o, Movie m);
};
Movie::Movie(string movie, string rating, int oneStar, int twoStar, int threeStar, int fourStar, int fiveStar) {
    name = movie;
    mpaaRating = rating;
    oneStarRatings = max(oneStar, 0);
    twoStarRatings = max(twoStar, 0);
    threeStarRatings = max(threeStar, 0);
    fourStarRatings = max(fourStar, 0);
    fiveStarRatings = max(fiveStar, 0);
}
void Movie::addRating(int rating) {
    if (rating < 1 || rating > 5) {
        cout << "Invalid rating. Discarded." << endl;
    }
    else {
        switch (rating) {
            case 1:
                oneStarRatings++;
                break;
            case 2:
                twoStarRatings++;
                break;
            case 3:
                threeStarRatings++;
                break;
            case 4:
                fourStarRatings++;
                break;
            case 5:
                fiveStarRatings++;
                break;
        }
    }
}
double Movie::getAverage() {
    return double(1 * oneStarRatings + 2 * twoStarRatings + 3 * threeStarRatings + 4 * fourStarRatings + 5 * fiveStarRatings) / double(oneStarRatings + twoStarRatings + threeStarRatings + fourStarRatings + fiveStarRatings);
}
ostream& operator<<(ostream& o, Movie m) {
    o << "Name: " << m.name << endl;
    o << "MPAA: " << m.mpaaRating << endl;
    o << "Stars: " << m.getAverage() << endl;
    return o;
}

int main() {
    string film, rated;
    cout << "Hello, please enter a movie name: " << endl;
    cin >> film;
    cout << "Please enter a movie MPAA Rating (G, PG, PG-13, R): " << endl;
    cin >> rated;
    Movie movie1(film, rated);

    bool done = false;
    while (!done) {
        char choice;
        cout << "Would you like to add a review for this movie? (y/n)" << endl;
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            done = true;
        }
        else {
            int review;
            cout << "Enter your review (1-5):" << endl;
            cin >> review;
            movie1.addRating(review);
        }
    }

    string film2, rated2;
    cout << "Thank you, please enter another movie name: " << endl;
    cin >> film2;
    cout << "Please enter the movie's MPAA Rating (G, PG, PG-13, R): " << endl;
    cin >> rated2;
    Movie movie2(film2, rated2);

    done = false;
    while (!done) {
        char choice;
        cout << "Would you like to add a review for this movie? (y/n)" << endl;
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            done = true;
        }
        else {
            int review;
            cout << "Enter your review (1-5):" << endl;
            cin >> review;
            movie2.addRating(review);
        }
    }

    cout << "Your movies are: " << endl;
    cout << movie1 << endl;
    cout << movie2 << endl;

    return 0;
}