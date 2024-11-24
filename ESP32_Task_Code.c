void task1(void *pvParameter) {
while(1) {
gpio_set_level(GPIO_NUM_2, 1); // Светодиод 1
vTaskDelay(500 / portTICK_PERIOD_MS);
gpio_set_level(GPIO_NUM_2, 0);
vTaskDelay(500 / portTICK_PERIOD_MS);
}
}

void task2(void *pvParameter) {
while(1) {
gpio_set_level(GPIO_NUM_4, 1); // Светодиод 2
vTaskDelay(1000 / portTICK_PERIOD_MS);
gpio_set_level(GPIO_NUM_4, 0);
vTaskDelay(1000 / portTICK_PERIOD_MS);
}
}

void app_main() {
    // Инициализация пинов GPIO
    gpio_set_direction(GPIO_NUM_2, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_4, GPIO_MODE_OUTPUT);

    // Создание задач
    xTaskCreate(task1, "Task 1", 2048, NULL, 1, NULL);
    xTaskCreate(task2, "Task 2", 2048, NULL, 1, NULL);
}
