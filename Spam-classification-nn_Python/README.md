# Классификация спама: полносвязная нейронная сеть на TensorFlow

Нейросеть (MLP, 164 параметра) для бинарной классификации электронных писем
на «спам» и «не спам» по 5 признакам: количество ссылок, объём текста,
наличие коммерческого предложения, репутация отправителя, использование CAPS.

Точность на тестовой выборке — **95.32%**.

**Стек:** Python, TensorFlow/Keras, Scikit-learn, Pandas, Matplotlib, Seaborn.

**Датасет:** [Kaggle — Spam Detection Dataset](https://www.kaggle.com/datasets/smayanj/spam-detection-dataset) (20 000 строк, 5 признаков)

## Ссылки

- [Код модели (Google Colab)](https://colab.research.google.com/drive/1HJ71Vpt_X0uQ9sVNnHQDlkSHrZO6D_8G)
- [HTML-интерфейс для проверки писем](https://disk.yandex.ru/d/Bd7VxpKTlvapHg)


