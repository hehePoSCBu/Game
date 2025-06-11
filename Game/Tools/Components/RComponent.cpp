#include "RComponent.h"

void RComponent::init(string model_path, Shader* shader)
{
    this->model = new Model(model_path);
    this->shader = shader;
}

void RComponent::onEnable()
{
    model->Draw(*(this->shader));
}
