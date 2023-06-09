#include <iostream>
#include <vector>
#include <gtkmm.h>

using namespace std;

class Window : public Gtk::Window {
public:
    Gtk::VBox vbox;
    Gtk::Entry entry1, entry2;
    Gtk::Button button1;
    Gtk::Label label, entryLabel1, entryLabel2;

    Window() {
        button1.set_label("Combine names");
        entryLabel1.set_text("First name");
        entryLabel2.set_text("Last name");

        vbox.pack_start(entryLabel1);
        vbox.pack_start(entry1);  //Add the widget entry1 to vbox
        vbox.pack_start(entryLabel2);
        vbox.pack_start(entry2);  //Add the widget entry2 to vbox
        vbox.pack_start(button1); //Add the widget button1 to vbox
        vbox.pack_start(label);  //Add the widget label to vbox

        add(vbox);  //Add vbox to window
        show_all(); //Show all widgets

        button1.set_sensitive(false);
        entry1.signal_changed().connect([this]() {
            if(entry1.get_text().size() > 0 && entry2.get_text().size() > 0)
                button1.set_sensitive(true);
            else
                button1.set_sensitive(false);
        });
        entry2.signal_changed().connect([this]() {
            if(entry1.get_text().size() > 0 && entry2.get_text().size() > 0)
                button1.set_sensitive(true);
            else
                button1.set_sensitive(false);
        });
        button1.signal_clicked().connect([this]() {
            label.set_text(entry1.get_text() + " " + entry2.get_text());
        });
    }
};

int main() {
    // Oppgave 1
    vector<double> numbers = {1.01, 3.2, 4.2, 5.0, 6};
    cout << "Front: " << numbers.front() << "\nBack: " << numbers.back() << endl;
    numbers.emplace(++numbers.begin(), 6.9);
    cout << "Front: " << numbers.front() << endl;
    cout << "Alle tall i vektoren: " << endl;
    for(double number : numbers) {
        cout << number << endl;
    }

    cout << "Finn tall 6:\n";
    auto found = find(numbers.begin(), numbers.end(), 6);
    if(found != numbers.end())
        cout << "Fant: " << *found << endl;

    // Oppgave 2
    Gtk::Main gtk_main;
    Window window;
    gtk_main.run(window);
}
