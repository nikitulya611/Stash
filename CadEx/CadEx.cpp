#include <iostream>
#include <cmath>
#include <random>
#include <algorithm>
#include <numeric>

#include <omp.h>

#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

using namespace std;

int main()
{
	const int count = 200;
	double t = PI / 4;
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<double> dist(1.0, 10.0);
	vector<Curve*> curves;

	for (int i = 0; i < count; i++) {
		curves.push_back(new Circle(dist(mt)));
	}

	for (int i = 0; i < count; i++) {
		curves.push_back(new Ellipse(dist(mt), dist(mt)));
	}

	for (int i = 0; i < count; i++) {
		curves.push_back(new Helix(dist(mt), dist(mt)));
	}

	cout << "Circles\t\tCoordinates\t\t\tDerivative\n";

	for (int i = 0; i < count; i++) {
		cout << i + 1 << "\t\t" << curves[i]->parFunc(t) << "\t\t" << curves[i]->derivative(t) << endl;
	}

	cout << "Ellipses\tCoordinates\t\t\tDerivative\n";

	for (int i = count; i < count * 2; i++) {
		cout << i + 1 << "\t\t" << curves[i]->parFunc(t) << "\t\t" << curves[i]->derivative(t) << endl;
	}

	cout << "Helixes\tCoordinates\t\t\tDerivative\n";

	for (int i = count * 2; i < count * 3; i++) {
		cout << i + 1 << "\t\t" << curves[i]->parFunc(t) << "\t\t" << curves[i]->derivative(t) << endl;
	}

	vector<Circle*> circles;
	//перемешаем элементы в изначальном векторе и воспользуемся RTTI
	shuffle(curves.begin(), curves.end(), mt);
	for (int i = 0; i < count * 3; i++) {
		Circle* c = dynamic_cast<Circle*>(curves[i]);
		if (c != nullptr)
			circles.push_back(c);
	}

	sort(circles.begin(), circles.end(), [](const auto & c1, const auto & c2) {return c1->getRadius() < c2->getRadius(); });

	cout << endl << endl;
	//убедимся что вектор корректно отсортирован
	for (int i = 0; i < circles.size(); i++) {
		cout << circles[i]->getRadius() << endl;
	}

	cout << "Seq:\n" << "Radius sum of 2nd vector: " << accumulate(circles.begin(), circles.end(), 0.0, [](double b, Circle * c) {return b + c->getRadius(); }) << endl;

	double sum = 0;
	int threadCount = 4;
	omp_set_num_threads(threadCount);
	int chunk = circles.size() / threadCount;

	//на моей машине почему-то запускается только с одним потоком, пофиксить не смог

#pragma omp parallel num_thread(threadCount) shared(sum)
	{
		if (omp_get_thread_num() + 1 == omp_get_num_threads()) {
			for (int i = chunk * omp_get_thread_num(); i < circles.size(); i++)
			{
				sum += circles[i]->getRadius();
			}
		}
		else {
			for (int i = 0; i < chunk; i++)
			{
				sum += circles[i + chunk * omp_get_thread_num()]->getRadius();
			}
		}
	}

	cout << "Parallel: " <<  sum;

	return 0;
}
