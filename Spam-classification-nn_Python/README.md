# Классификация спама: полносвязная нейронная сеть на TensorFlow

Нейросеть (MLP, 164 параметра) для бинарной классификации электронных писем
на «спам» и «не спам». Модель анализирует 5 признаков письма и определяет
вероятность спама с точностью **95.32%**. Для интерактивной проверки писем
разработан HTML-интерфейс.

## Признаки

| Признак | Описание |
|---------|----------|
| `num_links` | Количество гиперссылок в письме |
| `num_words` | Объём текста (в словах) |
| `has_offer` | Наличие коммерческого предложения (0/1) |
| `sender_score` | Репутация отправителя (0/1) |
| `all_caps` | Текст полностью заглавными буквами (0/1) |

## Архитектура модели

Вход (5 признаков) → StandardScaler ↓ Dense(12, HeUniform, L2=0.001) + ReLU + Dropout(0.2) ↓ Dense(6, HeUniform, L2=0.001) + ReLU + Dropout(0.2) ↓ Dense(2, L2=0.001) + Softmax → [P(не спам), P(спам)]


- **Оптимизатор:** Adam (learning rate = 0.0005)
- **Функция потерь:** sparse_categorical_crossentropy
- **Регуляризация:** L2 (λ = 0.001) + Dropout (0.2) — предотвращает переобучение
- **Preprocessing:** StandardScaler — стандартизация признаков (mean = 0, std = 1)

## Результаты

| Метрика | Значение |
|---------|----------|
| Test Accuracy | 95.32% |
| Test Loss | 13.63% |
| Обучающих примеров | 12 000 (60%) |
| Валидационных | 4 000 (20%) |
| Тестовых | 4 000 (20%) |

**Стек:** Python, TensorFlow/Keras 2.19.0, Scikit-learn, Pandas, Matplotlib, Seaborn

**Датасет:** [Kaggle — Spam Detection Dataset](https://www.kaggle.com/datasets/smayanj/spam-detection-dataset) (20 000 строк, 5 признаков, соотношение классов 91:9)

## Ссылки

- [Код модели (Google Colab)](https://colab.research.google.com/drive/1HJ71Vpt_X0uQ9sVNnHQDlkSHrZO6D_8G)
- [HTML-интерфейс для проверки писем](https://disk.yandex.ru/d/Bd7VxpKTlvapHg)



