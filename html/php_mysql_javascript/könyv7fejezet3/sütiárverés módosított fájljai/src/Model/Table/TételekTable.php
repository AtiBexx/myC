<?php
declare(strict_types=1);

namespace App\Model\Table;

use Cake\ORM\Query;
use Cake\ORM\RulesChecker;
use Cake\ORM\Table;
use Cake\Validation\Validator;

/**
 * Tételek Model
 *
 * @method \App\Model\Entity\Tételek newEmptyEntity()
 * @method \App\Model\Entity\Tételek newEntity(array $data, array $options = [])
 * @method \App\Model\Entity\Tételek[] newEntities(array $data, array $options = [])
 * @method \App\Model\Entity\Tételek get($primaryKey, $options = [])
 * @method \App\Model\Entity\Tételek findOrCreate($search, ?callable $callback = null, $options = [])
 * @method \App\Model\Entity\Tételek patchEntity(\Cake\Datasource\EntityInterface $entity, array $data, array $options = [])
 * @method \App\Model\Entity\Tételek[] patchEntities(iterable $entities, array $data, array $options = [])
 * @method \App\Model\Entity\Tételek|false save(\Cake\Datasource\EntityInterface $entity, $options = [])
 * @method \App\Model\Entity\Tételek saveOrFail(\Cake\Datasource\EntityInterface $entity, $options = [])
 * @method \App\Model\Entity\Tételek[]|\Cake\Datasource\ResultSetInterface|false saveMany(iterable $entities, $options = [])
 * @method \App\Model\Entity\Tételek[]|\Cake\Datasource\ResultSetInterface saveManyOrFail(iterable $entities, $options = [])
 * @method \App\Model\Entity\Tételek[]|\Cake\Datasource\ResultSetInterface|false deleteMany(iterable $entities, $options = [])
 * @method \App\Model\Entity\Tételek[]|\Cake\Datasource\ResultSetInterface deleteManyOrFail(iterable $entities, $options = [])
 */
class TételekTable extends Table
{
    /**
     * Initialize method
     *
     * @param array $config The configuration for the Table.
     * @return void
     */
    public function initialize(array $config): void
    {
        parent::initialize($config);

        $this->setTable('tételek');
        $this->setDisplayField('tételazonosító');
        $this->setPrimaryKey('tételazonosító');
    }

    /**
     * Default validation rules.
     *
     * @param \Cake\Validation\Validator $validator Validator instance.
     * @return \Cake\Validation\Validator
     */
    public function validationDefault(Validator $validator): Validator
    {
        $validator
            ->integer('tételazonosító')
            ->allowEmptyString('tételazonosító', null, 'create');

        $validator
            ->scalar('név')
            ->maxLength('név', 100)
            ->allowEmptyString('név');

        $validator
            ->scalar('leírás')
            ->allowEmptyString('leírás');

        $validator
            ->decimal('viszonteladóiár')
            ->allowEmptyString('viszonteladóiár');

        $validator
            ->integer('nyertesajánlattevő')
            ->allowEmptyString('nyertesajánlattevő');

        $validator
            ->decimal('nyertesár')
            ->allowEmptyString('nyertesár');

        return $validator;
    }
	
	public function findNyertesajánlattevő(Query $lekérdezés, array $lehetőségek)
	{
		$tételek = $this->find()->select(['tételazonosító', 'név','leírás', 'nyertesár']);
		$tételek->where(['Tételek.nyertesajánlattevő IN' => $lehetőségek['nyertesajánlattevő']]);
		return $tételek->group(['Tételek.tételazonosító']);
	}

}
